%% ͼ����ת
% ����ԭ��
% ��תǰ��x = r �� cos��  y = r �� sin��
% ��ת��x' = r �� cos(��-��) = r �� cos�� �� cos�� + r �� sin�� �� sin�� = x �� cos�� + y �� sin��
%                y' = r �� sin(��-��) = r �� sin�� �� cos�� - r �� cos�� �� sin�� = -x �� sin�� + y �� cos��
% �Ծ������ʽ��ʾΪ��
%             inv( [x'; y'; 1] ) =
%      ([ cos��, sin��, 0; -sin��, cos��, 0; 0, 0, 1 ]) * inv([ x, y, 1 ])
% ������Ϊ��
%             inv( [x; y; 1] ) =
%      ([ cos��, -sin��, 0; sin��, cos��, 0; 0, 0, 1 ]) * inv([ x', y', 1 ])
%
% ԭʼͼ�����������Ϊ�����������и������㣬�任���Ŀ��ͼ�������λ�ÿ��ܲ���������
% ���ԣ�ͼ�����ת��������Ҫ���м������㣬����Ҫ��Ŀ��ͼ�������λ�ý��в�ֵ����

%% ͼ���ֵ
% 1.����ڲ�ֵ      2.˫���Բ�ֵ      3.�����ڲ�ֵ

%  B = imrotate(A,ANGLE,METHOD) rotates image A, using the interpolation
%     method specified by METHOD. METHOD is a string that can have one of the
%     following values. The default value is enclosed in braces ({}).
%
%          {'nearest'}  Nearest neighbor interpolation
%
%          'bilinear'   Bilinear interpolation
%
%          'bicubic'    Bicubic interpolation. Note: This interpolation
%                       method can produce pixel values outside the original
%                       range.

function image_rotation = image_rotation(image_origin, rotate_angle, interpolation_mathod)

% image_rotation = imrotate(image_origin, rotate_angle, interpolation_mathod);

    rotate_radian = rotate_angle / 180 * pi;         % ����ת�ĽǶ�תΪ�û��ȱ�ʾ
    image_gray = rgb2gray(image_origin);         % ��ԭʼͼ��ת��Ϊ�Ҷ�ͼ
    [height, width] = size(image_gray);                % ����Ҷ�ͼ�ĸ߶ȺͿ��

    rot = [cos(rotate_radian), -sin(rotate_radian) 0; sin(rotate_radian), cos(rotate_radian), 0; 0, 0, 1];
    pixel_left_on = [1, 1, 1] * rot;                         % �任��ͼ�����ϵ������
    pixel_right_on = [1, w, 1] * rot;                       % �任��ͼ�����ϵ������
    pixel_left_down = [heiht, 1, 1] * rot;               % �任��ͼ�����µ������
    pixel_right_down = [height, wwidth, 1] * rot;  % �任��ͼ�����µ������

    rotate_height = round( max( [ abs( pixel_left_on(1) - pixel_right_down(1)) + 0.5,  ...
        abs( pixel_right_on(1) - pixel_left_down(1) ) + 0.5 ] ) );     % �任��ͼ��ĸ߶�
    rotate_width  = round( max( [ abs( pixel_left_on(2) - pixel_right_down(2) ) + 0.5, ...
        abs( pixel_right_on(2) - pixel_left_down(2) ) + 0.5] ) );      % �任��ͼ��Ŀ��

    delta_height = abs(min( [ pixel_left_on(1), pixel_right_on(1), 
        pixel_left_down(1), pixel_right_down(1) ] ) );                      %ȡ��hieght����ĸ��ᳬ����ƫ����
    delta_width = abs(min( [ pixel_left_on(2), pixel_right_on(2), 
        pixel_left_down(2), pixel_right_down(2) ] ) );                      %ȡ��width����ĸ��ᳬ����ƫ����
    
    for i = 1 - delta_height : height - delta_height
        for j = 1 - delta_width : width - delta_width
            pixel_origin = [i, j, 1] / rot;                                                  %�ñ任��ͼ��ĵ������ȥѰ��ԭͼ�������꣬
            % ������Щ�任���ͼ������ص��޷���ȫ���
            float_height = pixel_origin(1) - floor( pixel_origin(1) );
            float_width   = pixel_origin(2) - floor( pixel_origin(2) );
            
            if pixel_origin(1) >= 1 && pixel_origin(2) >= 1 && pixel_origin(1)  <= height && pixel_origin(2) <= widths
            %�ĸ����ڵĵ�
                pix_up_left = [floor(pix(1)), floor(pix(2))];
                pix_up_right = [floor(pix(1)), ceil(pix(2))];
                pix_down_left = [ceil(pix(1)), floor(pix(2))];
                pix_down_right = [ceil(pix(1)), ceil(pix(2))];
                
                value_up_left = (1-float_X)*(1-float_Y);              %�����ٽ��ĸ����Ȩ��
                value_up_right = float_X*(1-float_Y);
                value_down_left = (1-float_X)*float_Y;
                value_down_right = float_X*float_Y;
                
                imgn(i + delta_y, j + delta_x) = value_up_left * img(pix_up_left(1), pix_up_left(2)) +  ...
                    value_up_right * img(pix_up_right(1), pix_up_right(2)) + ...
                    value_down_left * img(pix_down_left(1), pix_down_left(2)) +  ...
                    value_down_right * img(pix_down_right(1), pix_down_right(2));
            end   
        end
    end

end
