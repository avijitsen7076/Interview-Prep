def matrix_reshape(mat, r, c)
    x = mat.flatten
    return mat if r*c != x.size
    x.each_slice(c).to_a
end
