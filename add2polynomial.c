#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int coeff; // Coefficient of the term
    int power; // Power of the term
} Term;

void addPolynomials(Term *poly1, int n1, Term *poly2, int n2)
{
    Term *result = (Term *)malloc((n1 + n2) * sizeof(Term));
    int i = 0, j = 0, k = 0;

    // Add the polynomials
    while (i < n1 && j < n2)
    {
        if (poly1[i].power > poly2[j].power)
        {
            result[k++] = poly1[i++];
        }
        else if (poly1[i].power < poly2[j].power)
        {
            result[k++] = poly2[j++];
        }
        else
        { // Same power, add coefficients
            result[k].power = poly1[i].power;
            result[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
    }

    // Copy remaining terms
    while (i < n1)
    {
        result[k++] = poly1[i++];
    }
    while (j < n2)
    {
        result[k++] = poly2[j++];
    }

    // Display the result
    printf("Resultant Polynomial: ");
    for (int m = 0; m < k; m++)
    {
        printf("%dx^%d", result[m].coeff, result[m].power);
        if (m < k - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");

    free(result);
}

int main()
{
    int n1, n2;

    // Input for first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    Term *poly1 = (Term *)malloc(n1 * sizeof(Term));
    printf("Enter coefficients and powers (coeff power):\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d %d", &poly1[i].coeff, &poly1[i].power);
    }

    // Input for second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    Term *poly2 = (Term *)malloc(n2 * sizeof(Term));
    printf("Enter coefficients and powers (coeff power):\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %d", &poly2[i].coeff, &poly2[i].power);
    }

    // Add the polynomials
    addPolynomials(poly1, n1, poly2, n2);

    // Free allocated memory
    free(poly1);
    free(poly2);

    return 0;
}
