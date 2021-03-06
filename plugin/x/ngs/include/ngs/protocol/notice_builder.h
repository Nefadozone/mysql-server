/*
 * Copyright (c) 2016, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have included with MySQL.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef PLUGIN_X_NGS_INCLUDE_NGS_PROTOCOL_NOTICE_BUILDER_H_
#define PLUGIN_X_NGS_INCLUDE_NGS_PROTOCOL_NOTICE_BUILDER_H_

#include <string>

#include "my_inttypes.h"
#include "plugin/x/ngs/include/ngs/protocol/message_builder.h"

namespace ngs {
class Output_buffer;

class Notice_builder : public Message_builder {
 public:
  void encode_frame(Page_output_stream *out_buffer, uint32 type,
                    const std::string &data, int scope);

  void encode_rows_affected(Page_output_stream *out_buffer, uint64 value);
};
}  // namespace ngs

#endif  // PLUGIN_X_NGS_INCLUDE_NGS_PROTOCOL_NOTICE_BUILDER_H_
