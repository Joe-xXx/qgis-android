#!/bin/bash

#   ***************************************************************************
#     necessitas-qtcreator.sh - Run necessitas qtcreator with the config.conf
#     environment variables set
#      --------------------------------------
#      Date                 : 29-Jul-2011
#      Copyright            : (C) 2011 by Marco Bernasocchi
#      Email                : marco at bernawebdesign.ch
#   ***************************************************************************
#   *                                                                         *
#   *   This program is free software; you can redistribute it and/or modify  *
#   *   it under the terms of the GNU General Public License as published by  *
#   *   the Free Software Foundation; either version 2 of the License, or     *
#   *   (at your option) any later version.                                   *
#   *                                                                         *
#   ***************************************************************************/


source `dirname $0`/config.conf
$NECESSITAS_DIR/QtCreator/bin/necessitas &
echo "to import android branch into necessitas do:
file -> open file or project open CMakeLists.txt
choose a build dirng
pass the cmake flags you obtain from echo $MY_CMAKE_FLAGS in build-qgis.sh"
 

