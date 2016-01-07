/***************************************************************************
 *   Copyright (C) 2015-2016 by Savoir-faire Linux                              *
 *   Author : Emmanuel Lepage Vallee <emmanuel.lepage@savoirfairelinux.com>*
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 **************************************************************************/

#pragma once

#include "typedefs.h"

class QWidget;
class Account;

/**
 * This class will automatically bridge QtDesigner .ui to the LRC Account::
 * class. To use it, all relevant .ui fields need to have in their name
 *
 * `lrcfg_propertyName` where `propertyName` is part of the Account object
 * roleName hash.
 *
 * Supported widgets are currently:
 *
 *  * QLineEdit
 */
class LIB_EXPORT AccountSerializationAdapter : public QObject
{
   Q_OBJECT
public:
   AccountSerializationAdapter(Account* a, QWidget* w);
   virtual ~AccountSerializationAdapter();
};

