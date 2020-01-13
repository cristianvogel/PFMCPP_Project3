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
#include <ctime>  // for random seeding

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

namespace PersonTask
{
struct Person 
{
    Person()  //constructor for Person UDT 
    { 
        age = 42; height = 178; 
        hairLength = 2.3f; GPA = 20;
        SATScore = 0; distanceTravelled = 0.0f;
    }

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    float distanceTravelled;
    
    struct Foot
    {
        Foot(){ stepSize = 0.5f; } // constructor for Foot UDT inside Person UDT

        float stepSize;

        float getStepSize()
        {
            //get stepSize
            std::cout << "Person::Foot::getStepSize() " << stepSize << std::endl; 
            return stepSize;
        }

        void stepForward()
        {
            //take a step forward
        }
    };

    Foot leftFoot;
    Foot rightFoot;

    void run (int, bool);
    
    void printAge()            //1) the member function for this task
    {
        std::cout << "Person::printAge() " << age << std::endl;   
    }     
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
    distanceTravelled += leftFoot.getStepSize() + rightFoot.getStepSize();
}

int main() 
{
    Person pavel;             
    pavel.printAge();     
    pavel.leftFoot.getStepSize();
    return 0;
}

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
namespace CarWashExample
{
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    CarWash()
    {
        numSponges = 3; 
        amountOfSoapUsedPerCar = 2.6;
        numCarsProcessed = 0;
    }
    int numSponges;
    double amountOfSoapUsedPerCar; //2) relevant data types
    unsigned int numCarsProcessed;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.

    void printNumSponges() // Member Function for Constructor task
    {
         std::cout << "CarWash:: sponge count -> " << numSponges << std::endl;   
    }
        
};

int main() 
{
    CarWash downTown;
    downTown.printNumSponges();
    return 0;
}
}
/*
 1)
 */
namespace KitchenExample
{
struct Kitchen
{
    Kitchen()
    {
        numberChefs = 1;
        numberOfAssistants = 3;
        numberOfStudents = 25;
    }

    unsigned int numberChefs;
    unsigned int numberOfAssistants;
    unsigned int numberOfStudents;

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

    void printNumberOfStudents() 
    {
        std::cout << "Kitchen::Number of Students -> " << numberOfStudents << std::endl;
    }
};

//Implementation 1
void Kitchen::startCookingClass (Chef chef, Recipe recipe)
{
    chef.isTeaching = true;
    recipe.currentStep = 0;
    chef.isMasterChef = (chef.codeName == recipe.creator.codeName);  
}

int main()
{
    Kitchen masterChef;
    masterChef.printNumberOfStudents();
    return 0;
}
}
/*
 2)
 */
namespace KioskLocatorTask 
{ 
struct KioskLocator
{
    KioskLocator()
    {
        isOpen = true; distance = 0.0f;
        starRating = 5; name = 'k';
    }

    bool isOpen;
    float distance;
    int starRating;
    char name;
    
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

    void printKioskLocatorName()
    {
        std::cout << "KioskLocator::printKioskLocatorName is -> " << name << std::endl;
    }
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

int main()
{
    KioskLocator KLM;
    KLM.printKioskLocatorName();
    return 0;
}
}

/*
 3)
 */
namespace ADSRTask
{
struct ADSR 
{
    ADSR() 
    {
        isRunning = false;
        timeScale = 'M';
        duration = 1.0;
    }

    bool isRunning;
    char timeScale;
    double duration;
    
    struct Stage 
    { 
        char stage = 'A';
        double stageDur = 0.5;
    };

    Stage currentStage;
    Stage getCurrentStage();

    void printDuration()
    {
         std::cout << "ADSR::duration is -> " << duration << std::endl;
    }
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

int main() 
{
    ADSR env;
    env.printDuration();
    return 0;
}

}

/*
 4)
 */
 namespace FormTask
 {
struct Form 
{
    bool isVisible;
    char formID;
    int fields;
    
    struct TextField 
    { 
        TextField() 
        {
            x = 80; y = 160; w = 400; h = 90;
            alpha = 32;
            fieldID = 'a'; hasCheckBox = true;
        }

        float x,y,w,h;
        int alpha;
        char fieldID;
        bool hasCheckBox;
    };

    struct CheckBox
    {
        CheckBox()
        {
            size = 16.0f;
            icon = '#';
            isChecked = false;
        }

        float size;
        char icon;
        bool isChecked;

        void animateCheckBox (char fieldID, CheckBox c);
    };

    CheckBox checkBox;
    TextField fullName;

    Form ()
    {
        isVisible = true;
        formID = 'f';
        fields = 4;
        fullName = TextField();
    }

    bool mouseOver (TextField fullName);
    bool formIsVisible (char formID);
    void clearAllCheckBoxes (Form f);
    void print_IDs()
    {
         std::cout << "Form::ids are FieldID ->  " << fullName.fieldID << " FormID ->  " << formID << " CheckBox ID ->  " << checkBox.icon <<std::endl;
    }
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


int main()
{
    Form submit;
    submit.print_IDs();
    return 0;
}

}

/*
 5)
 */
 
namespace PresetLibraryTask
{
struct PresetLibrary 
{
    PresetLibrary()
    {
        bank = 'A';
        presetNumber = 1;
        hasBeenEdited = false;
        seed = 0.001f;
    }

    char bank;
    int presetNumber;
    char presetName;
    bool hasBeenEdited;
    float seed;

    struct PresetName 
    {   
        // my first pointer! 
        // learned from cplusplus.com
        // gets random seed from time in the constructor
        PresetName()
        {
            time_t timeSeed;
            time (&timeSeed);
            numberOfChars = 8;
            name = this-> getRandomChars (timeSeed, numberOfChars);
        }

        std::string name;
        unsigned int numberOfChars;

        std::string getRandomChars (long, unsigned int);
    };

    PresetName presetNameObject;

    bool updatePresets();
    PresetLibrary dumpBank (char bank);
    /* DEPRECATED
    PresetName generateRandomName (char bank, int presetNumber, float seed);
    */

    std::string getPresetName();
    
};

//Implementation 5
std::string PresetLibrary::PresetName::getRandomChars (long seededWith, unsigned int lengthInChars) 
{
    /*
        ... Project 3 task psuedo app, I just lookup a char at random from a string....
    */
    std::string noisy = "asiodfunoiusfdyvnzxcvuybzxocv";
    unsigned noisyLength = unsigned(noisy.length());
    std::string result = "";
    std::srand(static_cast<unsigned>(seededWith));

    lengthInChars = (lengthInChars > noisyLength) ? noisyLength : lengthInChars;

    unsigned int index;
    for ( unsigned int j = 0; j< lengthInChars; ++j)
    {
        index = (static_cast<unsigned>(std::rand()))%lengthInChars; 
        char pick = noisy[ static_cast<size_t>(index) ];
        result += pick;
    }
    return result;
}

std::string PresetLibrary::getPresetName()
{
    PresetLibrary preset;
   // std::cout << "Debug: " << preset.presetNameObject.name << std::endl;
    return preset.presetNameObject.name;
}


bool PresetLibrary::updatePresets() 
{
    // refresh presetname list
    return {};
}

/* DEPRECATED
PresetLibrary::PresetName PresetLibrary::generateRandomName (char, int, float) 
{
    //come up with a random name STRING for a presetNumber in a bank
    return {};
}
*/

PresetLibrary PresetLibrary::dumpBank (char)
{
    //dump a whole bank into or from a UDT PresetLibrary
    //return a full or 'empty' PresetLibrary type
    return {};
}

int main() 
{
    PresetLibrary pl; 
    std::cout << "PresetLibrary::random name is ->  " << pl.getPresetName() << std::endl;
    return 0;
}

}
/*
 6)
 */
 namespace FunkyBufferPlayerTask
{
struct FunkyBufferPlayer 
{
    FunkyBufferPlayer()
    {
        bufferID = 1;
        defaultBufferSize = 60 * 5;
        numberOfBuffers = 4;
        loopCounter = 0;
    }

    int bufferID;
    double defaultBufferSize;
    int numberOfBuffers;
    int loopCounter;

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

    double printDefaultBufferSize()
    {
        return (this-> defaultBufferSize);
    }
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

int main() 
{
    FunkyBufferPlayer fbp;
    std::cout << "FunkyBufferPlayer::default size ->  "<< fbp.printDefaultBufferSize() << std::endl;
    return 0;
}

}

/*
 7)
 */
namespace FaderBankTask
{
struct FlyingFaderBank
{
 
    int numberOfFaders = {3};

    struct Fader
    {
        std::string id;
        bool physics = {true};
        float friction, accel, velocity = {0.5f};

        void update (std::string id, float friction, float accel, float velocity);
        float getValue (std::string id);
    };
//  Initialising structs from list overrides constructor default values
    Fader fader1 { "kik", false, 0.55f, 0.2f, 0.4f }, 
          fader2 { "snr", true, 0.1f, 0.33f, 0.5f }, 
          fader3 { "klp", false, 0.1f, 0.3f, 0.5f }; 

    std::string printFaderPhysics();
    std::string printFaderIDs();
    void updateFaders (int numberOfFaders);
};

//Implementation 7
std::string FlyingFaderBank::printFaderPhysics()
{
    std::string result = "";
    result += (fader1.physics) ? fader1.id+" true " : fader1.id+" false ";
    result += (fader2.physics) ? fader2.id+" true " : fader2.id+" false "; 
    result += (fader3.physics) ? fader3.id+" true " : fader3.id+" false ";   
    return result;
}

void FlyingFaderBank::updateFaders (int)
{
    //get status and values of a number of faders
}

void FlyingFaderBank::Fader::update (std::string, float, float, float)
{
    //update physics animation of a fader
}

float FlyingFaderBank::Fader::getValue (std::string)
{
    //return some value from fader data
    return {};
}

int main()
{
    FlyingFaderBank ffb;
    std::cout << "Faderbank ID & physics -> " << ffb.printFaderPhysics() << std::endl ;
    return 0;
}
}
/*
 8)
 */

namespace ScaleGeneratorTask
{
struct ScaleGenerator
{
    ScaleGenerator() {scaleName = 'a'; octaves = 8; stepSize = 1.618;}

    char scaleName;
    int octaves;
    double stepSize;
    
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

int main() 
{
    ScaleGenerator scale;
    std::cout << "Scale stepsize -> " << scale.stepSize << std::endl;
    return 0;
}
}

/*
 9)
 */
namespace MetersTask
{ 
struct Meter
{
    Meter()
    {
        meterID = 1; peakHold = true;
        colourPallette = 'a';
        slewRise = 0.1f; slewFall = 0.1f;
    }

    int meterID;
    bool peakHold;
    char colourPallette;
    float slewRise, slewFall;

    struct VerticalMeter 
    {   
        int w,h,x,y;
        float scaleFactor = {0.5f};
        int numberOfSegments = {32};

        struct Segment
        {
            Segment()
            {
                segmentIndex = 0; opacity = 0.5f; activeStatus = true;
            }

            ~Segment()
            {
                segmentIndex = -1; opacity = 0.0f; activeStatus = false;
                this->destroy();
            }

            int segmentIndex;
            float opacity;
            bool activeStatus;

            void destroy();
            void draw (int segmentIndex);
        };
        void updateSegment (int meterID, Segment s);
    };

    VerticalMeter vumeterType1 { 64, 16, 50, 10};   
    VerticalMeter vumeterType2 { 16, 64, 50, 50}; 
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
    //executes when removing an instance of a Segment UDT from memory 
}

int main() 
{
    Meter vu1, vu2;
    std::cout << "VuMeter1 x y w h ->  " << vu1.vumeterType1.x << "," << vu1.vumeterType1.y
    << "," << vu1.vumeterType1.w <<  "," << vu1.vumeterType1.h << std::endl;
    std::cout << "VuMeter2 x y w h ->  " << vu2.vumeterType2.x << "," << vu1.vumeterType2.y
    << "," << vu2.vumeterType2.w <<  "," << vu2.vumeterType2.h << std::endl;
    return 0;
}
}
/*
 10)
 */
namespace SequencerTask
{ 
struct StepSequencer
{
    StepSequencer()
    {
        isPlaying = false;
        numberOfSteps = 8;
        tempo = 120;
        id = 1;
        pitchClass = stepData.stepPitchClass.pitch; 
    }

    bool isPlaying;
    int numberOfSteps;
    double tempo;
    unsigned int id;
    char pitchClass; 
    int currentStage;

    struct StepData
    {
        struct PitchClass 
        {
            PitchClass()
            {
                frequency = 440;
               // pitch = pitchFromFreq (frequency);
               pitch = 'A';
            }

            double frequency;
            char pitch;
            
            char pitchFromFreq (double);
        };

        int currentStage = {1};

        PitchClass stepPitchClass;
        bool gateStatus = true;       
        double duration = 1.0;
    };

    int getCurrentStage (unsigned int id);
    void stepSequence (unsigned int id, bool isPlaying);
    
    StepData stepData;
    StepData getCurrentStepData();
};

//Implementation 10
char StepSequencer::StepData::PitchClass::pitchFromFreq (double)
{
    //here we would actually calculate the pitch class with precision and grace
    char result = 'A';
    return result;
}

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

int main()
{
    StepSequencer s1;
    std::cout << "Sequencer:: Pitch Class -> " << s1.pitchClass << std::endl;
    return 0;
}
}

#include <iostream>
int main()
{
	Example::main();
    PersonTask::main();
    CarWashExample::main();
    KitchenExample::main();
    KioskLocatorTask::main();
    ADSRTask::main();
    FormTask::main();
    PresetLibraryTask::main();
    FunkyBufferPlayerTask::main();
    FaderBankTask::main();
    ScaleGeneratorTask::main();
    MetersTask::main();
    SequencerTask::main();

    std::cout << "good to go!" << std::endl;
}
