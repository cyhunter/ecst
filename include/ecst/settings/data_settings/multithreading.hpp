// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/aliases.hpp>
#include <ecst/config.hpp>
#include <ecst/mp/core.hpp>
#include <type_traits>

ECST_SETTINGS_NAMESPACE
{
    namespace impl
    {
        constexpr auto v_singlethreaded = sz_v<0>;
        constexpr auto v_allow_inner_parallelism = sz_v<1>;
        constexpr auto v_disallow_inner_parallelism = sz_v<2>;
    } // namespace impl
}
ECST_SETTINGS_NAMESPACE_END
