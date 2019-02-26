#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

ILCOIND=${ILCOIND:-$SRCDIR/ilcoind}
ILCOINCLI=${ILCOINCLI:-$SRCDIR/ilcoin-cli}
ILCOINTX=${ILCOINTX:-$SRCDIR/ilcoin-tx}
ILCOINQT=${ILCOINQT:-$SRCDIR/qt/ilcoin-qt}

[ ! -x $ILCOIND ] && echo "$ILCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
ILCVER=($($ILCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for ilcoind if --version-string is not set,
# but has different outcomes for ilcoin-qt and ilcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$ILCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $ILCOIND $ILCOINCLI $ILCOINTX $ILCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${ILCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${ILCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
