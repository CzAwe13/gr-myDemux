#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2024 ziao chen.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
# from gnuradio import blocks
try:
    from gnuradio.myDemux import my_header_payload_demux
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from gnuradio.myDemux import my_header_payload_demux

class qa_my_header_payload_demux(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None
        
    def test_instance(self):
    # Provide appropriate arguments when creating the instance
    	instance = my_header_payload_demux(
        header_len=10, 
        items_per_symbol=1, 
        guard_interval=0,
        length_tag_key="frame_len",  # Add more arguments here
        trigger_tag_key="",          # Add more arguments here
        output_symbols=False,        # Add more arguments here
        itemsize=8,                  # Add more arguments here
        timing_tag_key="",           # Add more arguments here
        samp_rate=1.0,               # Add more arguments here
        special_tags=[],             # Add more arguments here
        header_padding=0             # Add more arguments here
    )

    def test_001_descriptive_test_name(self):
        # set up fg
        self.tb.run()
        # check data

if __name__ == '__main__':
    gr_unittest.run(qa_my_header_payload_demux)
