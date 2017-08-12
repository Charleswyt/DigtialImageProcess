%% ͼ���ƽ�Ʋ���
%   translate Translate units in sweepset
%   S = translate(S,M,C) translates the units using the conversion factors
%  in M (gain) and C (offset).
function image_translation = image_translation(image_origin, move_height, move_width)

% Method one:
% strel ���ڴ�����̬ѧ�ṹԪ��
move_height = fix(move_height);                                 % ͼ��ƽ�Ƹ߶�ȡ��
move_width = fix(move_width);                                    % ͼ��ƽ�ƿ��ȡ��
se = translate(strel(1), [move_height, move_width]);  % �ڽṹԪ��se�Ͻ���height��width�����ϵ�ƫ��
image_translation = imdilate(image_origin,se);           % ��̬ѧ����

% Method two:
%     image_gray = rgb2gray(image_origin);        % ��ԭʼͼ��ת��Ϊ�Ҷ�ͼ
%     [height, width] = size(image_gray);               % heightΪͼ��ĸ߶ȣ�widthΪͼ��Ŀ��
%     image_translation = image_origin;                % image_translation��ֵΪԭʼͼ��
%
%     for i = 1:height
%         for j = 1:width
%             if( (i - move_height > 0) && (i - move_height < height)...
%                     && (j - move_width > 0) && (j - move_width) < width)
%                 image_translation(i, j, 1:3) = image_origin(i - move_height, j - move_width, 1:3);
%              else
%                 image_translation(i, j,1:3) = 0;
%             end
%         end
%     end

end