/*
 Project 3 - Part 3
 video: Chapter 2 - Part 8
 Constructors tasks

 On a new branch named part3

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate a few of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}


struct Person 
{
    int age;
    int height;
    float hairlength;
    float GPA;
    unsigned int SATScore;
    float distanceTravelled;

    struct Foot
    {
        float stepSize()
        {
            //get stepSize
            return {};
        }

        void stepForward()
        {
            //take a step forward
        }
    };

    Foot leftFoot;
    Foot rightFoot;

    void run (int, bool);
};

void Person::run (int, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true) 
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    };
    distanceTravelled += leftFoot.stepSize() + rightFoot.stepSize();
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 3) be sure to write the correct full qualified name for the nested type's member functions.
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 Wait for my code review.
 */

/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};

/*
 1)
 */
struct Kitchen
{
    unsigned int numberChefs = 1;
    unsigned int numberOfAssistants = 3;
    unsigned int numberOfStudents = 25;

    struct Chef 
    {
        bool isCooking;
        bool isTeaching;
        bool isMasterChef;
        char codeName = 'C';
    };

    struct Recipe
    {
        bool completed = false;
        unsigned int currentStep = 0;
        bool requiresAssitant = true;
        char recipeID = 'A';
        float difficultyRating = 5.0f;
        Chef creator;
    };

    Recipe currentRecipe;
    Chef masterChef;

    void startCookingClass (Chef c, Recipe r);
};

//Implementation 1
void Kitchen::startCookingClass (Chef chef, Recipe recipe)
{
    chef.isTeaching = true;
    recipe.currentStep = 0;
    if (chef.codeName == recipe.creator.codeName) 
    {
        chef.isMasterChef = true;
    }
}

/*
 2)
 */
struct KioskLocator
{
    bool isOpen = true;
    float distance = 0.0f;
    int starRating = 5;
    char name = 'k';
    
    struct Kiosk 
    {
        float distance = 20.0f;
        char name = 'Z';
    };

    struct KList 
    {
        int initSize = 3;
        char prefix = 'K';
        Kiosk k;

        KList getClosestKiosks();
    };

    Kiosk closestKiosk;

    void refreshList (KList k, int initSize);
    void getClosestKiosk (KList klist);
};

//Implementation 2
void KioskLocator::refreshList (KList klist, int ) 
{
    // fetch initialSize entries of data from klist 
    klist.getClosestKiosks();

}

KioskLocator::KList KioskLocator::KList::getClosestKiosks() 
{
    // return a KList of closestKiosks
    return {};
}

void KioskLocator::getClosestKiosk (KList klist) 
{
    // set closest kiosk from a KList
    refreshList (klist,3);
    closestKiosk.name = 'A';
    closestKiosk.distance = 0.0f;
}

/*
 3)
 */
struct ADSR 
{
    bool isRunning = false;
    char timeScale = 'M';
    double duration = 1.0;
    
    struct Stage 
    { 
        char stage = 'A';
        double stageDur = 0.5;
    };

    Stage currentStage;
    Stage getCurrentStage();
};

//Implementation 3
ADSR::Stage ADSR::getCurrentStage() 
{   
    if ( currentStage.stageDur > 0 ) 
    {
        duration += currentStage.stageDur;
    } 
    else
    {
        //go to next stage or end
    }
    return {};
}

/*
 4)
 */
struct Form 
{
    bool isVisible = true;
    char formID = 'f';
    int fields = 4;
    
    struct TextField 
    { 
        float x,y,w,h;
        int alpha = 32;
        char fieldID = 'a';
        bool hasCheckBox = true;
    };

    struct CheckBox
    {
        float size = 16.0f;
        char icon = '#';
        bool isChecked = false;

        void animateCheckBox (char fieldID, CheckBox c);
    };

    CheckBox checkBox;
    TextField fullName;

    bool mouseOver (TextField fullName);
    bool formIsVisible (char formID);
    void clearAllCheckBoxes (Form f);
};

//Implementation 4
bool Form::mouseOver (TextField) 
{
    //return true when mouse is over a certain field
return {};
}

bool Form::formIsVisible (char) 
{
    //check if form is visible
    //make it visible if not
    //return a state
    return {};
}

void Form::CheckBox::animateCheckBox (char , CheckBox)
{
    /*
        do funky animation for a UDT CheckBox
        related to a UDT Field of a certain id
    */
}


/*
 5)
 */
struct PresetLibrary 
{
    char bank = 'A';
    int presetNumber = 1;
    char presetName;
    bool hasBeenEdited = false;
    float seed = 0.001f;

    struct PresetName 
    {
        char c;
        int numberOfChars;
        
        struct RandomName 
        {
            int keyX, keyY;
            
            char getCharAt (int keyX, int keyY);
        };

        RandomName rn;
    };

    bool updatePresets();
    PresetName generateRandomName (char bank, int presetNumber, float seed);
    PresetLibrary dumpBank (char bank);
};

//Implementation 5

bool PresetLibrary::updatePresets() 
{
    // refresh presetname list
    return {};
}

PresetLibrary::PresetName PresetLibrary::generateRandomName (char, int, float) 
{
    //come up with a random name for a presetNumber in a bank
    return {};
}

PresetLibrary PresetLibrary::dumpBank (char)
{
    //dump a whole bank into or from a UDT PresetLibrary
    //return a full or 'empty' PresetLibrary type
    return {};
}

char PresetLibrary::PresetName::RandomName::getCharAt (int, int)
{
    /*
        get some random icon or char/string as preset name
        from a 2D Collection somewhere
    */
    return {};
}

/*
 6)
 */
struct FunkyBufferPlayer 
{
    int bufferID = 1;
    double defaultBufferSize = 60 * 5;
    int numberOfBuffers = 4;
    int loopCounter = 0;

    struct Buffer 
    {
        double sizeInSamples;
        double getSizeInSamples (int bufferID);
        
        struct SecondaryBuffer
        {
            int bufferID;
            bool isReversed = true;
            int loopCounter = 0;

            void reverse (int bufferID);
        };

        bool clearBuffer (int bufferID);
        bool copyToSecondaryBuffer (SecondaryBuffer bufferID);
    };
};

//Implementation 6

double getSizeInSamples (int) 
{
    //return the size of a Buffer instance
    return {};
}

bool FunkyBufferPlayer::Buffer::clearBuffer (int)
{
    // empty some buffer really fast
    // return when done
    return {};
}

bool FunkyBufferPlayer::Buffer::copyToSecondaryBuffer (SecondaryBuffer) 
{
    //duplicate a buffer into an instance of a SecondaryBuffer
    return {};
}

void FunkyBufferPlayer::Buffer::SecondaryBuffer::reverse (int)
{
    //some kind of reversi on an instance of a SecondaryBuffer
    //Get Funky
}


/*
 7)
 */
struct FlyingFaderBank
{
    int numberOfFaders = 3;

    struct Fader 
    {
        int id;
        bool physics = true;
        float friction, accel, velocity = 0.5f;

        void update (int id, float friction, float accel, float velocity);
        float getValue (int id);
    };

    Fader fader1, fader2, fader3;

    void updateFaders (int numberOfFaders);
};

//Implementation 7
void FlyingFaderBank::updateFaders (int)
{
    //get status and values of a number of faders
}

void FlyingFaderBank::Fader::update (int, float, float, float)
{
    //update physics animation of a fader
}

float FlyingFaderBank::Fader::getValue (int)
{
    //return some value from fader data
    return {};
}

/*
 8)
 */
struct ScaleGenerator
{
    char scaleName = 'a';
    int octaves = 8;
    double stepSize = 1.618;
    
    struct Scale 
    {
        Scale generateScaleForOctaves (int octaves, double stepSize);
    };

    Scale goldenRatio;
};

//Implementation 8
ScaleGenerator::Scale ScaleGenerator::Scale::generateScaleForOctaves (int, double)
{
    //naive scale generation returns as/into ScaleGenerator::Scale UDT
    return {};
}

/*
 9)
 */
struct Meter
{
    int meterID = 1;
    bool peakHold = true;
    char colourPallette = 'a';
    float slewRise, slewFall = 0.1f;

    struct VerticalMeter 
    {   
        int w,h,x,y;
        float scaleFactor = 0.5f;
        int numberOfSegments = 32;

        struct Segment
        {
            int segmentIndex;
            float opacity;
            bool activeStatus;

            void destroy();
            void draw (int segmentIndex);
        };
        void updateSegment (int meterID, Segment s);
    };
};

//Implementation 9
void Meter::VerticalMeter::updateSegment (int, Meter::VerticalMeter::Segment)
{
    //update segment graphics style
}

void Meter::VerticalMeter::Segment::draw (int)
{
    //draw an instance of a Segment UDT
}

void Meter::VerticalMeter::Segment::destroy()
{
    //remove an instance of a Segment UDT from memory
}

/*
 10)
 */
struct StepSequencer
{
    bool isPlaying = true;
    int numberOfSteps = 8;
    double tempo = 120;
    unsigned int id = 1;
	
    struct StepData
    {
        struct PitchClass 
        {
            double frequency;
            double pitch;

            double calculatePitchFromFreq (double frequency );
        };

        PitchClass p;
        bool gateStatus = true;       
        double duration = 1.0;
    };

    int getCurrentStage (unsigned int id );
    void stepSequence (unsigned int id, bool isPlaying );
    
    StepData stepData;
    StepData getCurrentStepData();
};

//Implementation 10
StepSequencer::StepData StepSequencer::getCurrentStepData() 
{
    // get all current StepData return in a StepData UDT 
    return {};
}

void StepSequencer::stepSequence(unsigned int, bool)
{
    //move to next stage in sequence
} 

int StepSequencer::getCurrentStage(unsigned int)
{
    //get stage number of current row with an ID
    return {};
} 

#include <iostream>
int main()
{
	Example::main();
    std::cout << "good to go!" << std::endl;
}
