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

#include "pch.h"
#include "detail.h"

namespace retro::app::api
{

	map::map(std::shared_ptr<project> project) noexcept
		: m_project(project)
	{
	}

	void map::on_create(const detail::property_tree& pt)
	{
		m_width = pt.get().get<std::int32_t>("<xmlattr>.width", 0);
		m_height = pt.get().get<std::int32_t>("<xmlattr>.height", 0);
		m_tile_width = pt.get().get<std::int32_t>("<xmlattr>.tilewidth", 0);
		m_tile_height = pt.get().get<std::int32_t>("<xmlattr>.tileheight", 0);

		for (const auto& [tag, child] : pt.get())
		{
			if (tag == "group")
			{
				auto group = std::make_shared<layer_group>(shared_from_this());
				group->on_create(detail::property_tree(child));
				m_layers.push_back(group);
			}
		}

		/*

		for (const auto& [tag, child] : pt)
		{
			if (tag == "layer")
			{
				auto tile_layer = std::make_shared<tile_layer>(shared_from_this());
				tile_layer->on_create(child);
				m_layers.push_back(tile_layer);
			}
			else if (tag == "objectgroup")
			{
				auto object_group = std::make_shared<object_group>(shared_from_this());
				object_group->on_create(child);
				m_layers.push_back(object_group);
			}
			else if (tag == "imagelayer")
			{
				auto image_layer = std::make_shared<image_layer>(shared_from_this());
				image_layer->on_create(child);
				m_layers.push_back(image_layer);
			}
			else if (tag == "group")
			{
				auto layer_group = std::make_shared<layer_group>(shared_from_this());
				layer_group->on_create(child);
				m_layers.push_back(layer_group);
			}
		}
		
		*/
	}

}