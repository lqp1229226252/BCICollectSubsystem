import logging
import os
import warnings
import mne.io as io
import argparse
import numpy as np


def readFile(args):
    filedata = io.read_raw_brainvision(args.path)
    data, times = filedata[:, :]
    ch_names = filedata.info["ch_names"]
    os.mkdir(args.temp)
    data = np.transpose(data, (1, 0))
    data.tofile(args.temp + "/data.bin")
    np.savetxt(args.temp + "/ch_names.txt", ch_names, fmt="%s")


if __name__ == '__main__':
    logging.disable()
    warnings.filterwarnings('ignore')

    parser = argparse.ArgumentParser()
    parser.add_argument("--path", type=str, default='', help="file path")
    parser.add_argument("--temp", type=str, default='', help="file of temp path")
    args = parser.parse_args()

    readFile(args)
