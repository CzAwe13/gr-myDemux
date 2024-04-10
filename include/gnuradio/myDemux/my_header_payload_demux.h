/* -*- c++ -*- */
/*
 * Copyright 2024 ziao chen.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_MYDEMUX_MY_HEADER_PAYLOAD_DEMUX_H
#define INCLUDED_MYDEMUX_MY_HEADER_PAYLOAD_DEMUX_H

#include <gnuradio/block.h>
#include <gnuradio/myDemux/api.h>

namespace gr {
namespace myDemux {

/*!
 * \brief <+description of block+>
 * \ingroup myDemux
 *
 */
class MYDEMUX_API my_header_payload_demux : virtual public block
{
public:
    typedef std::shared_ptr<my_header_payload_demux> sptr;

    /*!
     * \param header_len Number of symbols per header
     * \param items_per_symbol Number of items per symbol
     * \param guard_interval Number of items between two consecutive symbols
     * \param length_tag_key Key of the frame length tag
     * \param trigger_tag_key Key of the trigger tag
     * \param output_symbols Output symbols (true) or items (false)?
     * \param itemsize Item size (bytes per item)
     * \param timing_tag_key The name of the tag with timing information, usually
     * 'rx_time' or empty (this means timing info is discarded) \param samp_rate Sampling
     * rate at the input. Necessary to calculate the rx time of packets. \param
     * special_tags A vector of strings denoting tags which shall be preserved (see \ref
     * hpd_tag_handling) \param header_padding A number of items that is appended and
     * prepended to the header.
     */
    static sptr
    make(const int header_len,
         const int items_per_symbol = 1,
         const int guard_interval = 0,
         const std::string& length_tag_key = "frame_len",
         const std::string& trigger_tag_key = "",
         const bool output_symbols = false,
         const size_t itemsize = sizeof(gr_complex),
         const std::string& timing_tag_key = "",
         const double samp_rate = 1.0,
         const std::vector<std::string>& special_tags = std::vector<std::string>(),
         const size_t header_padding = 0);
};

} // namespace myDemux
} // namespace gr

#endif /* INCLUDED_MYDEMUX_MY_HEADER_PAYLOAD_DEMUX_H */
