%% ���������ݶȵ���
function weights = neighbor_gradien_reciprocal(neighbor_block)

gradient_block = neighbor_gradient(neighbor_block);
[height, width] = size(gradient_block);
weights = zeros(height, width);
weights((height+1)/2, (width+1)/2) = 0.5;
block_sum = 2.0 * sum(gradient_block(:));

for h = 1:height
    for w = 1:width
        weights(h, w) = gradient_block(h, w) / block_sum;
    end
end

weights((height+1)/2, (width+1)/2) = 0.5;

end