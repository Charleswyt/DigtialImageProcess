%%  ͼ��ľ���任
% ʹ��˵����
% image_mirror(image_origin, mirror_method)
% image_origin��ԭʼͼ��
% mirror_method���任��ʽ���̶�"horizental"(ˮƽ����)��"vertical"(��ֱ����)����ѡ��

function image_mirror = image_mirror(image_origin, mirror_method)

% Method one:
%     flipdim(X,DIM) returns X with dimension DIM flipped
%     image_vertical_mirror     = flipdim(image_origin,1);   % ͼ��Ĵ�ֱ����
%     image_horizental_mirror = flipdim(image_origin,2);   % ͼ���ˮƽ����

%     if strcmp(mirror_method, 'horizental') == 1
%         image_mirror = flipdim(image_origin, 2);
%     elseif strcmp(mirror_method, 'vertical') == 1
%         image_mirror = flipdim(image_origin, 1);
%     else
%         disp('Error: Mirror direction error!');
%     end

% Method two:
image_gray = rgb2gray(image_origin);           % ��ԭʼͼ��ת��Ϊ�Ҷ�ͼ
[height, width] = size(image_gray);                  % ����Ҷ�ͼ�ĸ߶ȺͿ��
image_mirror = image_origin;                          % image_mirror��ʼֵΪԭʼͼ��

if strcmp(mirror_method, 'horizental') == 1
    for i = 1 : height - 1
        for j = 1 : width - 1
            image_mirror(i, j, 1:3) = image_origin(i, width - j, 1:3);
        end
    end
    
elseif strcmp(mirror_method, 'vertical') == 1
    for i = 1 : height - 1
        for j = 1 : width - 1
            image_mirror(i, j, 1:3) = image_origin(height - i, j, 1:3);
        end
    end
    
else
    disp('Error: Mirror direction error!');
end

end