double smallest_circle(Point *a, int n, Point &O) {
    random_shuffle(a, a + n);
    O = a[0];
    double r = 0;
    for (int i = 0; i < n; ++i) {
        if (r * r < (O - a[i]).len2()) {
            O = a[i];
            r = 0;
            for (int j = 0; j < i; ++j) {
                if (r * r < (O - a[j]).len2()) {
                    O = middle(a[i], a[j]);
                    r = (O - a[j]).len();
                    for (int k = 0; k < j; ++k) {
                        if (r * r < (O - a[k]).len2())
                            r = circumscribed_circle(a[i], a[j], a[k], O);
                    }
                }
            }
        }
    }
    return r;
}
