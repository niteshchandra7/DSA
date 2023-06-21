import os
from glob import glob
import shutil
from sklearn.model_selection import train_test_split


xml_files = glob("../input/car-damage/Internship/annot_chem4/*.xml")
image_files = glob("../input/car-damage/Internship/images_chem4/*.jpg")
train_names, val_names = train_test_split(image_files, test_size=0.3)


train = "./car_damage_dataset/train"
val = "./car_damage_dataset/val"
train_annot = "./car_damage_dataset/train_annot"
val_annot = "./car_damage_dataset/val_annot"


def move_img_files(file_list, destination_path):
    for file in file_list:  # extracting only the name of the file and concatenating with extenions
        shutil.copy(file, destination_path)
    return


def move_xml_files(file_list, destination_path):
    for file in file_list:
        file = file.replace(".jpg", ".xml").replace("images_chem4", "annot_chem4")
        shutil.copy(file, destination_path)
    return


move_img_files(train_names, train)
move_img_files(val_names, val)
move_xml_files(train_names, train_annot)
move_xml_files(val_names, val_annot)
