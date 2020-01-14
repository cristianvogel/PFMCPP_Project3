/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>

namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl 
        << std::endl;;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
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
    unsigned int numberChefs;
    unsigned int numberOfAssistants;
    unsigned int numberOfStudents;

    struct Recipe
    {
        bool completed;
        unsigned int currentStep;
        char recipeID;
        char creator;

        Recipe();
    };

    struct Chef 
    {
        bool isCooking;
        bool isTeaching;
        bool isMasterChef;
        char codeName;
        Recipe currentRecipe; 

        Chef();
    };
 
    Chef chef;

    Kitchen();
    
    void setMasterChef();
    void startCookingClass (Chef , Recipe);
    void printMasterChefStatus ( Chef );
};

Kitchen::Kitchen() : numberChefs(1), numberOfAssistants(3), numberOfStudents(25) {}

Kitchen::Chef::Chef() : 
    isCooking (true), 
    isTeaching (false), 
    isMasterChef (false), //member initialisation sets masterchef status to false
    codeName ('C') 
{} 

Kitchen::Recipe::Recipe() : completed (false), currentStep (0), recipeID ('A'), creator ('C') {}

//Implementation 1

void Kitchen::setMasterChef() 
{
    //sets masterchef status of aChef reference
    bool isMC = (this->chef.codeName == chef.currentRecipe.creator);
    this->chef.isMasterChef = isMC;
}

void Kitchen::startCookingClass (Chef aChef, Recipe recipe)
{
    aChef.isTeaching = true;
    recipe.currentStep += 1;

    setMasterChef();

    std::cout << "Kitchen::Cooking class started." << std::endl;
}

void Kitchen::printMasterChefStatus (Chef aChef) 
{
    std::cout << "Kitchen::Chef Name? -> " << aChef.codeName << std::endl;
    std::cout << "Kitchen::Recipe Created by? -> " << aChef.currentRecipe.creator << std::endl;
    std::cout << "Kitchen::Master Chef? -> " << ((aChef.isMasterChef) ? "yes" : "no") << std::endl 
    << std::endl;
}

int main()
{
    Kitchen zanzibars;

    zanzibars.startCookingClass ( zanzibars.chef, zanzibars.chef.currentRecipe);
    zanzibars.printMasterChefStatus( zanzibars.chef );
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
    bool isOpen;
    float distance;
    int starRating;
    char name;

    KioskLocator() : isOpen (true), distance ( 0.0f ), starRating ( 5 ), name ( 'K' ) { }
    
    struct Kiosk 
    {
        char name;
        float distance;

        Kiosk();
    };

    struct KList 
    {
        int initSize;
        char prefix;
        Kiosk k;

        KList getClosestKiosks();

        KList();
    };

    Kiosk closestKiosk;

    void refreshList (KList k, int initSize);
    void getClosestKiosk (KList klist);

    void printKioskLocatorName()
    {
        std::cout << "KioskLocator::printKioskLocatorName is -> " << name << std::endl;
        std::cout << "KioskLocator::Closest Kiosk is -> " << closestKiosk.name << std::endl
        << std::endl;
    }
};

KioskLocator::KList::KList() : initSize (32), prefix ( 'a' ) { }
KioskLocator::Kiosk::Kiosk() : name ( 'Z'), distance ( 20.0f ) { }

//Implementation 2
void KioskLocator::refreshList (KList klist, int ) 
{
    // fetch and dostuff with entries of data from klist 
    klist.getClosestKiosks();
    //do stuff
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
    bool isRunning;
    char timeScale;
    double duration;
    int numberOfStages;
    
    struct Stage 
    { 
        char stage;
        double stageDur;

        Stage();
    };

    Stage currentStage;

    Stage getCurrentStage();

    void printStageDur (Stage envStage)
    {
        if ((numberOfStages) > 0) envStage.stageDur = duration/numberOfStages;
        //no Type conflict because the first Type in the division takes precedence

        std::cout << "ADSR::curent stage dur is -> " << envStage.stageDur << std::endl
        << std::endl;
    }
    void printDuration()
    {
         std::cout << "ADSR::duration is -> " << duration << std::endl;
    }

    ADSR();
};

ADSR::ADSR() : isRunning ( false ), timeScale ( 'M' ), duration ( 5 ), numberOfStages ( 3 ) { }
ADSR::Stage::Stage() : stage ('A'), stageDur ( 1 ) {}

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
    env.printStageDur( env.currentStage );
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
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        CheckBox()
        {
            size = 16.0f;
            icon = '#';           
        }

        bool isChecked { false };
        bool isVisible { true };
        float size;
        char icon;

        void animateCheckBox (std::string fieldID, CheckBox c);
    };

    struct TextField 
    { 
        float x,y,w,h;
        int alpha;
        std::string fieldID;
        CheckBox fieldCheckBox;

        TextField(); 
    };

    CheckBox checkBox;
    TextField fullName;

    bool mouseOver (TextField fullName);
    bool formIsVisible (std::string formID);
    void clearAllCheckBoxes (Form f);
    void print_IDs()
    {
         std::cout << "Form::ids are FieldID ->  " << fullName.fieldID << " FormID ->  " << formID << " CheckBox ID ->  " << fullName.fieldCheckBox.icon << std::endl
         <<std::endl;
    }

    Form();
};

Form::Form() :
            isVisible ( true ),
            formID ( "UserName" ),
            fields ( 4 ),
            fullName ( TextField() ) 
{ } 

Form::TextField::TextField() : 
                            x ( 80 ), y ( 160 ), w ( 400 ), h ( 90 ),
                            alpha ( 32 ),
                            fieldID ( "FullName" ),
                            fieldCheckBox ( CheckBox() )
{ }

//Implementation 4
bool Form::mouseOver (TextField) 
{
    //return true when mouse is over a certain field
return {};
}

bool Form::formIsVisible (std::string ) 
{
    //check if form is visible
    //make it visible if not
    //return a state
    return {};
}

void Form::CheckBox::animateCheckBox (std::string , CheckBox)
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
    struct PresetName 
    {   
        // my first pointer! 
        // learned from cplusplus.com
        // gets random seed from time in the constructor
        PresetName()
        {
            time_t timeSeed;
            time (&timeSeed);
            numberOfChars = {8};
            name = this-> getRandomChars (timeSeed, numberOfChars);
        }

        std::string name;
        unsigned int numberOfChars;

        std::string getRandomChars (long, unsigned int);
    };

    PresetName presetNameObject;

    char bank;
    int presetNumber = { 001 };
    bool hasBeenEdited = { false };
    float seed;
    std::string presetName = presetNameObject.name;

    bool updatePresets();
    PresetLibrary dumpBank (char bank);
    std::string getPresetName();
    
    PresetLibrary();
};

PresetLibrary::PresetLibrary() : bank ( 'B' ), seed ( 0.2f ) { }

//Implementations 5
std::string PresetLibrary::getPresetName()
{
    return presetNameObject.name;
}

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

bool PresetLibrary::updatePresets() 
{
    // refresh presetname list
    return {};
}

PresetLibrary PresetLibrary::dumpBank (char)
{
    //TODO: dump a whole bank into or from a UDT PresetLibrary
    //return a full or 'empty' PresetLibrary type
    return {};
}

int main() 
{
    PresetLibrary pl; 
    std::cout << "PresetLibrary:: random name is ->  " << pl.getPresetName() << 
    " from seed -> " << pl.seed << std::endl
    << std::endl;
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
    struct Buffer 
    {   
        struct SecondaryBuffer
        {
            int bufferID;
            double sizeInSamples = getSizeInSamples (bufferID);
            bool isReversed = true;
            int loopCounter = { 0 };

            void reverse (int );
            double getSizeInSamples (int );
        };

        int bufferID;
        double sizeInSamples = getSizeInSamples (bufferID);
        int loopCounter = { 0 };

        double getSizeInSamples (int );
        bool clearBuffer (int );
        bool copyToSecondaryBuffer (SecondaryBuffer );

        Buffer();        
    };

    double defaultBufferSize;
    int numberOfBuffers;
    Buffer mainBuffer;

    double getDefaultBufferSize()
    {
        return (this-> defaultBufferSize);
    }

    FunkyBufferPlayer();
};
FunkyBufferPlayer::Buffer::Buffer() : bufferID( 2 ) { }

FunkyBufferPlayer::FunkyBufferPlayer() :
                                        defaultBufferSize ( 2048 ),
                                        numberOfBuffers ( 4 ),
                                        mainBuffer ( Buffer ())
{ }

//Implementation 6

double FunkyBufferPlayer::Buffer::getSizeInSamples (int id) 
{
    //return the size of a Buffer instance
    double sizeInSamp;
    switch ( id )
    {
        case 1: sizeInSamp = 512; break;
        case 2: sizeInSamp = 4096; break;
        case 3: sizeInSamp = 8192; break;
        default: sizeInSamp = 2048; break; // wanted this value to come from parent UDT...don't know how yet
    }
    return sizeInSamp;
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
    std::cout << "FunkyBufferPlayer:: size of buffer "<< fbp.mainBuffer.bufferID  << " is " << fbp.mainBuffer.sizeInSamples  << std::endl << std::endl;
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
    char scaleName;
    int octaves;
    double stepSize;
    
    struct Scale 
    {
        Scale generateScaleForOctaves (int octaves, double stepSize);
    };

    Scale goldenRatio;

    ScaleGenerator() {scaleName = ( 'a' ); octaves = ( 8 ); stepSize = ( 1.618 );}

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
            int segmentIndex;
            float opacity;
            bool activeStatus;

            void destroy();
            void draw (int segmentIndex);
                       
            Segment();                 
            ~Segment()
            {
                segmentIndex = -1; opacity = 0.0f; activeStatus = false;
                this->destroy();
            }

        };
        void updateSegment (int meterID, Segment s);
    };

    VerticalMeter vumeterType1 { 64, 16, 50, 10 };   
    VerticalMeter vumeterType2 { 16, 64, 50, 50 }; 
};

Meter::VerticalMeter::Segment::Segment() :
                                        segmentIndex ( 0 ),
                                        opacity ( 0.5f ),
                                        activeStatus ( true )
{}

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
    struct StepData
    {
        struct PitchClass 
        {
            PitchClass()
            {
                frequency = 440;
               //TODO: pitch = pitchFromFreq (frequency);
                pitch = 'A';
            }

            double frequency;
            char pitch;
            
            char pitchFromFreq (double);
        };

        int currentStage = { 1 };

        PitchClass stepPitchClass;

        char pitchClass = stepPitchClass.pitch;
        bool gateStatus = true;       
        double duration = 1.0;

        StepData();
    };

    int getCurrentStage (unsigned int id);
    void stepSequence (unsigned int id, bool isPlaying);
    
    StepData stepData;
    StepData getCurrentStepData();

    bool isPlaying;
    int numberOfSteps;
    double tempo;
    unsigned int id;
    char pitchClass { stepData.pitchClass }; 
    int currentStage { stepData.currentStage };

    StepSequencer();
};

StepSequencer::StepData::StepData() :
                                currentStage ( 1 ),
                                gateStatus ( true ),
                                duration ( 1.0 )                            
{ }

StepSequencer::StepSequencer() :
                                isPlaying ( false ),
                                numberOfSteps ( 8 ),
                                tempo ( 120 ),
                                id ( 1 )
{ }


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
