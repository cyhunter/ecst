// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/aliases.hpp>
#include <ecst/config.hpp>
#include <ecst/ctx/types.hpp>
#include <limits>

namespace ecst::ctx::entity
{
    namespace impl
    {
        /// @brief Invalid entity ID used for invalid handles.
        constexpr auto invalid_id = std::numeric_limits<
            vrmc::underlying_if_strong_typedef_type<entity_id>>::max();
    } // namespace impl

    /// @brief Returns `true` if `eid` is a valid entity ID.
    ECST_CONST_FN inline bool is_valid_id(entity_id eid) noexcept
    {
        return eid != impl::invalid_id;
    }
} // namespace ecst::ctx::entity