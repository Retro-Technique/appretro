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
#include "engine.h"
#include "command_line_info.h"

namespace retro::app
{

	bool engine::run(int argc, char** argv)
	{
		boost::log::add_console_log(std::clog, boost::log::keywords::format = "[%TimeStamp%] [%Severity%]: %Message%");
		boost::log::add_common_attributes();

		BOOST_LOG_TRIVIAL(info) << "______________________________________________________________";
		BOOST_LOG_TRIVIAL(info) << "___    |__  __ \\__  __ \\__  __ \\__  ____/__  __/__  __ \\_  __ \\";
		BOOST_LOG_TRIVIAL(info) << "__  /| |_  /_/ /_  /_/ /_  /_/ /_  __/  __  /  __  /_/ /  / / /";
		BOOST_LOG_TRIVIAL(info) << "_  ___ |  ____/_  ____/_  _, _/_  /___  _  /   _  _, _// /_/ / ";
		BOOST_LOG_TRIVIAL(info) << "/_/  |_/_/     /_/     /_/ |_| /_____/  /_/    /_/ |_| \\____/  engine v" APPRETRO_VERSION;
		BOOST_LOG_TRIVIAL(info) << ""; BOOST_LOG_TRIVIAL(info) << "";
		BOOST_LOG_TRIVIAL(info) << "Optimized for Tiled Map Editor v" TILED_MAP_EDITOR_VERSION;

		try
		{
			const command_line_info cli = parse_command_line(argc, argv);
			if (cli.help)
			{
				return true;
			}

		}
		catch (const std::exception& e)
		{
			BOOST_LOG_TRIVIAL(error) << e.what();
			return false;
		}

		return true;
	}

}