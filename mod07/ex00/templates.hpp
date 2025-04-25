
template <typename T>
void swap(T &a, T &b) {
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
const T &min(const T &a, const T &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	if (a > b)
		return a;
	return b;
}