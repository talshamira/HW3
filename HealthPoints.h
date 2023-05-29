

class HealthPoints
{
    public:
        /*
         * constuctor for HealthPoints
         * @param  maxPoints is the max health points allowed
         */
        HealthPoints(const int maxPoints = 100);
        
        /*
         * Exception to throw for invalid argument
         */
        void InvalidArgument();

        /*
         * Constructor for HealthPoints with no parameters
         * Needed for operator implementation 
         */
        HealthPoints();

        /*
         * operator -= subtracts from current health the given health 
         * and makes sure current health doesnt go bellow zero
         * @param health given health to subtract
         */
        HealthPoints& operator-=(const int health);

        /*
         * binary operator - subtracts from current healthpoints the health given and returns the result
         * @param health an int specifing the amount to be subtracted shouldnt be <= 0
         */
        HealthPoints operator-(const int health);

        /*
         * Copy Constructor
         * needed for operator overloading
         */
        HealthPoints(const HealthPoints& old);

        /*
         * Operator = 
         * required because of copy constructor *********************************************************************************maybe needed
         */
       //HealthPoints& operator=(const HealthPoints old);

         /*
         * operator -= adds to current health the given health 
         * and makes sure current health doesnt go above m_maxHealthPoints
         * @param health given health to add
         */
        HealthPoints& operator+=(const int health);

        /*
         * binary operator + adds to current healthpoints the health given and returns the result
         * @param health an int specifing the amount to be added shouldnt be <= 0
         */
        HealthPoints operator+(const int health);


        /*
         * operator == checks if the given HealthPoints object has the same amount of health as the object 
         * @param b given paramater to check
         */
        friend bool operator==(const HealthPoints& a, const HealthPoints& b);

        /*
         * operator != checks if the given Healthpoints object had a diffrent amount of health as the object
         * @param b given parameter to check
         */
        friend bool operator!=(const HealthPoints& a, const HealthPoints& b);

        /*
         * operator >= checks if the given HealthPoints object has less health than or equall to the object 
         * @param b given paramater to check
         */
        friend bool operator<=(const HealthPoints& a, const HealthPoints& b);

        /*
         * operator >= checks if the given HealthPoints object has more health than or equall to the object
         * @param b given parameter to check
         */
        friend bool operator>=(const HealthPoints& a, const HealthPoints& b);

        /*
         * operator >= checks if the given HealthPoints object has less health than the object 
         * @param b given paramater to check
         */
        friend bool operator>(const HealthPoints& a, const HealthPoints& b);

        /*
         * operator >= checks if the given HealthPoints object has more health than the object
         * @param b given parameter to check
         */
       friend bool operator<(const HealthPoints& a, const HealthPoints& b);

        friend HealthPoints& HealthPoints::operator<<(HealthPoints health);
    private:
        int m_healthPoints;
        int m_maxHealthPoints;  
        static const int DEFAULT_MAX_HEALTH = 100;  
};