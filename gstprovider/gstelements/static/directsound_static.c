/*
 * Copyright (C) 2005 Sebastien Moutte <sebastien@moutte.net>
 * Copyright (C) 2007 Pioneers of the Inevitable <songbird@songbirdnest.com>
 * Copyright (C) 2008 Barracuda Networks, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 *
 * The development of this code was made possible due to the involvement
 * of Pioneers of the Inevitable, the creators of the Songbird Music player
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "../directsound/gstdirectsoundsink.h"
#include "../directsound/gstdirectsoundsrc.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  if (!gst_element_register (plugin, "directsoundsink", GST_RANK_PRIMARY,
          GST_TYPE_DIRECTSOUND_SINK))
    return FALSE;
  if (!gst_element_register (plugin, "directsoundsrc", GST_RANK_PRIMARY,
          GST_TYPE_DIRECTSOUND_SRC))
    return FALSE;

  return TRUE;
}

void gstelements_directsound_register()
{
  gst_plugin_register_static(
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    "directsound",
    "Direct Sound plugin library",
    plugin_init,
    "1.0.0",
    "LGPL",
    "my-application",
    "my-application",
    "http://www.my-application.net/"
    );
}