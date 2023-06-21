import os
import xmltodict
import json


def create_image_key(filename, img_list):
    """ Images """
    image_dict = dict()
    image_dict['filename'] = filename[:-3] + 'png'
    image_dict['id'] = int(filename[6:-4])
    img_list.append([image_dict])
    return img_list


def create_annotation_key(filename, annotation, annot_list):
    """Annotation"""
    for elem in annotation['object']:
        if type(elem) != dict:
            continue
        if elem['bndbox']:
            annot_dict = dict()
            xmin = int(elem['bndbox']['xmin'])
            ymin = int(elem['bndbox']['ymin'])
            xmax = int(elem['bndbox']['xmax'])
            ymax = int(elem['bndbox']['ymax'])
            width = xmax - xmin
            height = ymax - ymin
            annot_dict['bbox'] = [xmin, ymin, width, height]
            annot_dict['area'] = width*height
            annot_dict['image_id'] = int(filename[6:-4])
            annot_dict['id'] = annot_dict.get('image_id')
            annot_dict['iscrowd'] = 0
            annot_dict['category_id'] = 1
            annot_list.append(annot_dict)
    return annot_list


def create_categories_key(categories_list):
    categories_dict = dict()
    categories_dict['name'] = 'person'
    categories_dict['id'] = 1
    categories_dict['supercategory'] = 'person'
    categories_list.append(categories_dict)
    return categories_list


if __name__ == '__main__':
    my_dict: dict = dict()
    entries = os.listdir('Dataset/valid')
    GLOBAL_PATH = 'Dataset/valid/'
    annot_list = []
    img_list = []
    category_list = []
    for entry in entries:
        if entry.find('png') != -1:
            continue
        with open(GLOBAL_PATH + entry, 'r', encoding='utf-8') as file:
            my_xml = file.read()
            o = xmltodict.parse(my_xml)
            o = o['annotation']
            img_list = create_image_key(entry, img_list)
            annot_list = create_annotation_key(entry, o, annot_list)
    category_list = create_categories_key(category_list)
    my_dict['images'] = img_list
    my_dict['annotations'] = annot_list
    my_dict['categories'] = category_list
    json_dict = json.dumps(my_dict, indent=4)
    print(json_dict)
