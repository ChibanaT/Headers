class CTimer{

    private:
            long int start;
            long int pause;
            bool paused;

    public:

        CTimer(){
            start = clock();
            paused = false;
        }
        ~CTimer(){
        }
        double GetElapsedTime()
        {
            if(paused)
                return (pause - start) / (double)CLOCKS_PER_SEC;
            else
                return (clock() - start) / (double)CLOCKS_PER_SEC;            
        }

    void Pause(){
        if (!paused){
            paused = true;
            pause = clock();
        }
    }

    void Continue(){
        if (paused){
            long int elapsed = pause - start;
            start = clock() - elapsed;
            paused = false;
        }
    } 

    void Restart(){
        paused = false;
        start = clock();
    }

    CTimer* Copy(){
        CTimer* other = new CTimer();
        other -> start = start;
        other -> pause = pause;
        other -> paused = paused;
        
        return other;
    }
};

typedef CTimer* Timer;