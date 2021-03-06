//
// Copyright (C) 2009  Ole Andr� Vadla Ravn�s <oleavr@gmail.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#include "Stdafx.h"

#include "Monitor.hpp"

#include "util.h"

namespace oSpyAgent
{
    namespace Hooks
    {
        void Monitor::SetLogger(IEventLogger ^logger)
        {
            this->logger = logger;
            this->coordinator = logger->Coordinator;
        }

        String ^Monitor::BacktraceHere()
        {
            void *address = static_cast<void *>(HookRuntimeInfo::AddressOfReturnAddress);
            return gcnew String(CUtil::CreateBackTrace(address).c_str());
        }

        String ^Monitor::BoolToString(BOOL value)
        {
            return (value) ? "TRUE" : "FALSE";
        }
    }
}
