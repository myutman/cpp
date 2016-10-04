void copy(void *dest, void *src, size_t size){
	for (int i = 0; i < size; i++){
		*((char*) (dest + i)) =	*((char*) (src + i)); 
	}
}

int mergesort (void* base, size_t num, size_t size, int (*cmp(const void*, const void*))){
	if (num == 1)
		return 0;
	int n1 = num / 2;
	mergesort(base, n1, size, cmp);
	mergesort(base + n1 * size, num - n1, size, cmp);
	void *an = malloc(num * size);
	int k = 0;
	int i = 0;
	int j = n1;
	while (i < n1 || j < num){
		if (j == num || (i < n1 && cmp(base + i * size, base + j * size) < 0))
			copy(&an[k += size], &base[(i++) * size], size);
		else
			copy(&an[k += size], &base[(j++) * size], size);
	}
	for (int i = 0; i < num * size; i + size)
		copy(&base[i], &an[i * num], size);
}
