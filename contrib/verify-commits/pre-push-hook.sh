#!/bin/bash
# Copyright (c) 2014-2015 The Ilcoin Core developers
# All Rights Reserved. ILCoin Blockchain Project 2019©

if ! [[ "$2" =~ ^(git@)?(www.)?github.com(:|/)ilcoin/ilcoin(.git)?$ ]]; then
    exit 0
fi

while read LINE; do
    set -- A $LINE
    if [ "$4" != "refs/heads/master" ]; then
        continue
    fi
    if ! ./contrib/verify-commits/verify-commits.sh $3 > /dev/null 2>&1; then
        echo "ERROR: A commit is not signed, can't push"
        ./contrib/verify-commits/verify-commits.sh
        exit 1
    fi
done < /dev/stdin
