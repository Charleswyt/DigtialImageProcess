clc;
clear all;
close all;

image_path = 'C:\Users\Administrator\MatlabProject\DIP\1.jpg';
%% ---------------- image read ---------------- %%
image_origin  = imread(image_path);                                                     % ��ȡͼ��
image_gray    = rgb2gray(image_origin);                                                 % ��ɫͼ��ת�Ҷ�ͼ��
[heigth, width] = size(image_gray);                                                     % heightΪͼ��߶ȣ�widthΪͼ����

%% ------- image space trans -------- %%
% mirror
% image_mirror = image_mirror(image_origin, mirror_method)
% image_originΪ������ͼ��
% mirror_method : 'horizental'��ʾˮƽ����'vertical'��ʾ��ֱ����
image_mirror = image_mirror(image_origin, 'horizental');

% translation
move_x = 25;
move_y = 25;
image_translation = image_translation(image_origin, move_x, move_y);

% cut
start_x = 10;
start_y = 10;
crop_size_x = 300;
crop_size_y = 300;
image_crop = imcrop(image_origin, [start_x, start_y, crop_size_x, crop_size_y]);

% rotate
rotate_angle = 45;
% interpolation_mathod : nearest bilinear bicubic
image_rotation_nearest = image_rotation(image_origin, rotate_angle, 'nearest');         % ����ڲ�ֵ
image_rotation_bilinear = image_rotation(image_origin, rotate_angle, 'bilinear');       % ˫���Բ�ֵ
image_rotation_bicubic = image_rotation(image_origin, rotate_angle, 'bicubic');         % �����ڲ�ֵ

% ����

%% ---------------- image show ---------------- %%
%imshow(image_origin);                                                                  % ��ʾ��ɫͼ��
%imshow(image_gray);                                                                    % ��ʾ�Ҷ�ͼ��
%imshow(image_mirror);                                                                  % ��ʾ����ͼ��
%imshow(image_translation);                                                             % ��ʾƽ��ͼ��
%imshow(image_crop);                                                                    % ��ʾ�ü�ͼ��
%imshow(image_rotation_nearest);                                                        % ��ʾ��תͼ��
%inshow(image_)
