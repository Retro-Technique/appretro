/**
 *
 * appretro
 *
 * CEA CNRS INRIA LOGICIEL LIBRE
 *
 * Copyright(c) 2014-2025 Retro Technique
 *
 * This software is a computer program whose purpose is to provide
 * modern C++ minimalist cross-platform 2D game engine.
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 *
 */

#pragma once

#ifndef __APPRETRO_API_H_INCLUDED__
#error "Do not include this file directly, include <appretro/api.h> instead."
#endif

namespace retro::app::api
{

	class APPRETRO_API_API map : public std::enable_shared_from_this<map>
	{
	public:

		friend class project;

		map() = delete;
		explicit map(std::shared_ptr<project> project) noexcept;
		~map() = default;
		map(const map&) = delete;
		map& operator=(const map&) = delete;
		map(map&&) noexcept = default;
		map& operator=(map&&) noexcept = default;

		[[no_discard]] std::weak_ptr<project> get_project() const noexcept { return m_project; }
		[[no_discard]] constexpr std::size_t width() const noexcept { return m_width; }
		[[no_discard]] constexpr std::size_t height() const noexcept { return m_height; }
		[[no_discard]] constexpr std::size_t tile_width() const noexcept { return m_tile_width; }
		[[no_discard]] constexpr std::size_t tile_height() const noexcept { return m_tile_height; }
		[[no_discard]] constexpr std::size_t size() const noexcept { return width() * height(); }
		[[no_discard]] constexpr std::size_t width_pixels() const noexcept { return width() * tile_width(); }
		[[no_discard]] constexpr std::size_t height_pixels() const noexcept { return height() * tile_height(); }
		[[no_discard]] constexpr std::size_t size_pixels() const noexcept { return width_pixels() * height_pixels(); }

	protected:

		void on_create(const detail::property_tree& pt);
		void on_destroy();

		std::weak_ptr<project> m_project;
		std::vector<std::shared_ptr<layer>> m_layers;
		std::size_t m_width;
		std::size_t m_height;
		std::size_t m_tile_width;
		std::size_t m_tile_height;

	};

}