#include <stdio.h>
#include <math.h>

int main(){

    int 
    Ax, Ay,
    Bx, By,
    Cx, Cy;
    
    printf("A: "); scanf("%d %d", &Ax, &Ay);
    printf("B: "); scanf("%d %d", &Bx, &By);
    printf("C: "); scanf("%d %d", &Cx, &Cy);

    int Px, Py;
    printf("Point: "); scanf("%d %d", &Px, &Py);

    // info about ABC
    int 
    ABx = Bx - Ax, ABy = By - Ay,
    ACx = Cx - Ax, ACy = Cy - Ay,
    BCx = Cx - Bx, BCy = Cy - By;

    float ab = sqrt(ABx*ABx + ABy*ABy);
    float bc = sqrt(BCx*BCx + BCy*BCy);
    float ac = sqrt(ACx*ACx + ACy*ACy);

    float abc_sp = (ab + bc + ac) / 2;

    float abc_area = sqrt(abc_sp * (abc_sp - ab) * (abc_sp - bc) * (abc_sp - ac));


    /* C .   
         | .
         |    . 
         |       .
       A ---------- B
    */

    // Precalculate all sides
    int 
    PAx = Px - Ax, PAy = Py - Ay,
    PBx = Px - Bx, PBy = Py - By,
    PCx = Px - Cx, PCy = Py - Cy;

    float pa =  sqrt(PAx*PAx + PAy*PAy);
    float pb =  sqrt(PBx*PBx + PBy*PBy);
    float pc =  sqrt(PCx*PCx + PCy*PCy);

    // PAC

    float pac_sp = (pa + pc + ac) / 2.0;
    float pac_area = sqrt(pac_sp * (pac_sp - pa) * (pac_sp - pc) * (pac_sp - ac));

    // PAB

    float pab_sp = (pa + pb + ab) / 2;
    float pab_area = sqrt(pab_sp * (pab_sp - pa) * (pab_sp - pb) * (pab_sp - ab));

    // PBC

    float pbc_sp = (pb + pc + bc) / 2;
    float pbc_area = sqrt(pbc_sp * (pbc_sp - pb) * (pbc_sp - pc) * (pbc_sp - bc));

    // small epsilon
    const double EPS = 0.0001;

    float combined = (pac_area + pab_area + pbc_area);
    float diff = (combined - abc_area) >= 0 ? combined - abc_area : -(combined - abc_area);

    int is_inside = diff <= EPS;

    printf("Is point inside: %s", is_inside ? "yes" : "no");
    return 0;
}