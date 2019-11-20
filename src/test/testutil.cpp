// Copyright (c) 2009-2016 The Ilcoin Core developers
// All Rights Reserved. ILCoin Blockchain Project 2019©

#include "testutil.h"

#ifdef WIN32
#include <shlobj.h>
#endif

#include <boost/filesystem.hpp>

boost::filesystem::path GetTempPath() {
    return boost::filesystem::temp_directory_path();
}
