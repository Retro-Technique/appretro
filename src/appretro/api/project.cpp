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

	project::project(const std::filesystem::path& tiled_project) noexcept
		: m_tiled_project{ false, tiled_project }
		, m_tiled_map{ false, {} }
		, m_map(nullptr)
	{
	}

	void project::swap_map(const std::filesystem::path& tiled_map)
	{
		m_tiled_map = { false, tiled_map };
	}

	void project::on_create()
	{
		if (!m_tiled_project.created)
		{
			boost::property_tree::ptree pt;
			boost::property_tree::read_json(m_tiled_project.file.string(), pt);

			for (const auto& prop : pt.get_child("properties"))
			{
				prop.second.get<std::string>("<xmlattr>.name");
				prop.second.get<std::string>("<xmlattr>.value");	
				prop.second.get<std::string>("<xmlattr>.type");
			}

			m_tiled_project.created = true;
		}

		if (!m_tiled_map.created)
		{
			m_map.reset();

			boost::property_tree::ptree pt;
			boost::property_tree::read_xml(m_tiled_map.file.string(), pt);
				
			m_map = std::make_shared<map>(shared_from_this());
			m_map->on_create(detail::property_tree(pt.get_child("map")));

			m_tiled_map.created = true;
		}
	}

}