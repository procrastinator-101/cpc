/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



void change_color(int **r, int r_size, int *r_col_size, int sr, int sc, int nc, int patient_zero)
{
	r[sr][sc] = nc;
    if (sr > 0 && sc < r_col_size[sr - 1] && r[sr - 1][sc] == patient_zero)                 //up pixel
        change_color(r, r_size, r_col_size, sr - 1, sc, nc, patient_zero);
    if (sr < r_size - 1 && sc < r_col_size[sr + 1] && r[sr + 1][sc] == patient_zero)     //down pixel
        change_color(r, r_size, r_col_size, sr + 1, sc, nc, patient_zero);
    if (sc > 0 && r[sr][sc - 1] == patient_zero)										//left pixel
        change_color(r, r_size, r_col_size, sr, sc - 1, nc, patient_zero);
    if (sc < r_col_size[sr] - 1 && r[sr][sc + 1] == patient_zero)
        change_color(r, r_size, r_col_size, sr, sc + 1, nc, patient_zero);
}

//returnSize should be filled
int**   floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* r_size, \
		int** r_col_size)
{
	int **r;
	int *col_size;

	r = malloc(sizeof(int *) * imageSize);
	col_size = malloc(sizeof(int) * imageSize);
	for (int i = 0; i < imageColSize; i++)
	{
		r[i] = malloc(sizeof(int) * imageColSize[i]);
		for (int j = 0; j < imageColSize[i]; j++)
			r[i][j] = image[i][j];
		col_size[i] = imageColSize[i];
	}
	*r_size = imageSize;
	*r_col_size = col_size;
	change_color(r, imageSize, col_size, sr, sc, newColor, image[sr][sc]);
	return (r);
}
