/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_CONFIGMGR_SOURCE_READDCONFLAYER_HXX
#define INCLUDED_CONFIGMGR_SOURCE_READDCONFLAYER_HXX

#include <sal/config.h>

namespace configmgr { struct Data; }

namespace configmgr {

void readDconfLayer(Data & data, int layer);

}

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
