#import necessary packages
import numpy as np
import argparse
import cv2
import sys
from pathlib import Path

""" FILE = Path(__file__).resolve()
ROOT = FILE.parents[0]
if str(ROOT) not in sys.path:
    sys.path.append(str(ROOT))  # add ROOT to PATH
ROOT = Path(os.path.relpath(ROOT, Path.cwd()))  # relative """



def run():
    current_directory = Path.cwd()
    image_filepath = current_directory.joinpath(f'{image_name}.jpg')

#construct the argument parser
def parse_opt()
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--image", required = True, help = "Path to Image")
    parser.add_argument("-n", "--name", help="name of the image")
    opt = parser.parse_args()
    image_name = args.name
    print_args(vars(opt))
    return opt

#load the image, clone it for output, convert to grayscale
image = cv2.imread(args["image"])

def main(opt):
    run(**vars(opt))

if __name__ == '__main__':
    opt = parse_opt()
    main(opt)