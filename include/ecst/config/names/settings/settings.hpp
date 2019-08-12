// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config/names/global.hpp>

#define ECST_IMPL_SETTINGS_NAMESPACE \
    ECST_NAMESPACE                   \
    {                                \
        namespace settings

#define ECST_IMPL_SETTINGS_NAMESPACE_END \
    }                                    \
    ECST_NAMESPACE_END

/// @macro Opens the `ecst::settings` namespace.
#define ECST_SETTINGS_NAMESPACE ECST_IMPL_SETTINGS_NAMESPACE

/// @macro Closes the `ecst::settings` namespace.
#define ECST_SETTINGS_NAMESPACE_END ECST_IMPL_SETTINGS_NAMESPACE_END
