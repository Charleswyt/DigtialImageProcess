%%  ͼ��ľ���任
% ʹ��˵����
% image_mirror(image_origin, mirror_method)
% image_origin��ԭʼͼ��
% mirror_method���任��ʽ���̶�"horizental"(ˮƽ����)��"vertical"(��ֱ����)����ѡ��

function image = image_mirror(image_origin, mirror_method)

% Method one:
%     flipdim(X,DIM) returns X with dimension DIM flipped
%     image_vertical_mirror     = flipdim(image_origin,1);          % ͼ��Ĵ�ֱ����
%     image_horizental_mirror = flipdim(image_origin,2);            % ͼ���ˮƽ����

%     if strcmp(mirror_method, 'horizental') == 1
%         image_mirror = flipdim(image_origin, 2);
%     elseif strcmp(mirror_method, 'vertical') == 1
%         image_mirror = flipdim(image_origin, 1);
%     else
%         disp('Error: Mirror direction error!');
%     end

% Method two:
[height, width, channel] = size(image_origin);                      % ����ԭʼͼ��ĸ߶ȺͿ��
image = image_origin;                                               % image��ʼֵΪԭʼͼ��

if strcmp(mirror_method, 'horizental') == 1 || strcmp(mirror_method, '1') == 1
    for h = 1 : height
        for w = 1 : width - 1
            image(h, w, 1:channel) = image_origin(h, width - w, 1:channel);
        end
    end
    
elseif strcmp(mirror_method, 'vertical') == 1 || strcmp(mirror_method, '2') == 1
    for h = 1 : height - 1
        for w = 1 : width
            image(h, w, 1:channel) = image_origin(height - h, w, 1:channel);
        end
    end
    
else
    disp('Error: Mirror direction error!');
end

end