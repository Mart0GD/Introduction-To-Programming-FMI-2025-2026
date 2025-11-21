

int main(){

    // ------------------------------------------------------
    // Be mindfull when using VLA. C is not made to be safe!!!
    // ------------------------------------------------------

    { // zero value
        int n = 0;
        int VLA[n]; // undefined behaviour
    }
    
    { // negative value
        int n = -5;
        int VLA[n]; // undefined behaviour
    }

    { // unreachable block
        if(0){ 
            int n = -5;
            int VLA[n]; // undefined behaviour
        }
    }
    
    { // n is not initialized
        int n;  
        int VLA[n]; // undefined behaviour
    }

    { // to big a size
        int n = 1ULL << 31;
        int VLA[n];
    }

    { // lifetime ended
        
        int *ptr;
        {
            int n = 10;
            int VLA[n];
            ptr = &VLA;
        }

        *ptr = 1; // undefined bahaviour 
    }

}