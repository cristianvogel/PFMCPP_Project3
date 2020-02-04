/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
#include <random>

namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()



#include <iostream>
#include <ctime> // for time() function

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
        int minutesCooking {0};
        int timeAllowed {15};

        void setMinutesCooking( int mins )
        {
            minutesCooking = mins;
        }

        Chef();
    };
 
    Chef chef;

    Kitchen();

    bool checkTimer ( Chef currentChef )
    {
        bool timesUp = !currentChef.isCooking;

        if ( currentChef.minutesCooking > chef.timeAllowed)
        {
            timesUp = true;
            currentChef.isCooking = false;
            std::cout << "\t Chef - Times Up! \n";
        } 
        return timesUp;
    }

    void setMasterChef();
    void startCookingClass (Chef , Recipe);
    void printMasterChefStatus ( Chef );
};

Kitchen::Kitchen() : numberChefs(1), numberOfAssistants(3), numberOfStudents(25) {}

Kitchen::Chef::Chef() : 
    isCooking (false), 
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
    aChef.isCooking = true;
    recipe.currentStep += 1;

    setMasterChef();
    aChef.setMinutesCooking(0);

    std::cout << "Kitchen::Cooking class started." << "\n";
}

void Kitchen::printMasterChefStatus (Chef aChef) 
{
    std::cout << "Kitchen::Chef Name? -> " << aChef.codeName << std::endl;
    std::cout << "Kitchen::Recipe Created by? -> " << aChef.currentRecipe.creator << std::endl;
    std::cout << "Kitchen::Master Chef? -> " << ((aChef.isMasterChef) ? "yes" : "no") << std::endl 
    << std::endl; //Good use of ternary expression!
}

int main()
{
    Kitchen zanzibars;

    std::cout << "\n \nMemory used by Kitchen -> " << sizeof(Kitchen) << " bytes" << std::endl;

    zanzibars.startCookingClass ( zanzibars.chef, zanzibars.chef.currentRecipe);
    zanzibars.checkTimer( zanzibars.chef );
    zanzibars.printMasterChefStatus( zanzibars.chef );
    /// 20 minutes later
    zanzibars.chef.setMinutesCooking(20);
    zanzibars.checkTimer( zanzibars.chef );

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
        int listSize;
        char prefix;
        Kiosk k;

        //default constructor
        KList();

        //alternative constructor
        KList (int newSize, char newPrefix )
        {
            listSize = newSize;
            prefix = newPrefix;
        }
    };

    Kiosk closestKiosk;
    KList listOfKiosks;

    KList getClosestKiosks();
    void refreshList ();
    void getClosestKiosk (KList klist);

    void printKioskLocatorName()
    {
        std::cout << "KioskLocator::printKioskLocatorName is -> " << name << std::endl;
        std::cout << "KioskLocator::Closest Kiosk is -> " << closestKiosk.name << std::endl;
    }
};

KioskLocator::KList::KList() : listSize (32), prefix ( 'a' ) { }
KioskLocator::Kiosk::Kiosk() : name ( 'Z'), distance ( 20.0f ) { }

//Implementation 2
void KioskLocator::refreshList() 
{
    // fetch and dostuff with entries of data from klist 
    getClosestKiosks();
    //do stuff
}

KioskLocator::KList KioskLocator::getClosestKiosks() 
{
    // simulated return of a KList of random size
    // using standard library PRNG in this scope
    // set initial seed value to system clock https://www.learncpp.com/cpp-tutorial/59-random-number-generation/
    // seed and randomInt only used in this scope
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    int randomInt  = static_cast<int>(std::rand()%32);

    KList retrievedGeoData ( 0, 'r'); //use alternative constructor

    if (randomInt > 0)
    { 
        retrievedGeoData.listSize = randomInt;
    } 

    std::cout << "Finding Kiosks-> ";
    int listSize = retrievedGeoData.listSize;
    std::string gui = ""; //gui needs to be defined outside of the for loop

    for (int i=0; i<=listSize; ++i)
    { 
       gui += (i!=listSize) ? " | " :  "\n";
    }

    std::cout << gui;
    return retrievedGeoData;
}

void KioskLocator::getClosestKiosk (KList ) 
{
     // set closest kiosk from a KList
     
    refreshList();
    closestKiosk.name = 'A';
    closestKiosk.distance = 0.0f;
}

int main()
{
    KioskLocator KLM;
    KLM.getClosestKiosks();
    std::cout << "Memory used by KioskLocator -> " << sizeof(KioskLocator) << " bytes\n";
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
    struct Stage 
    { 
        char stage;
        double stageDur;
        int id;

        Stage();
    };

    bool isRunning;
    char timeScale;
    int numberOfStages;
    Stage currentStage;
    double duration = numberOfStages * currentStage.stageDur;
    
    Stage scaleCurrentStage();

    void scaleStageDurationByTimeScale ()
    {
        //if ((numberOfStages) > 0) envStage.stageDur = duration/numberOfStages;
        //no Type conflict because the first Type in the division takes precedence

        auto currentDur = scaleCurrentStage().stageDur;
        std::cout << "ADSR::scaled stage dur in mode -> " << timeScale <<" is now -> " << currentDur << std::endl;
    }

    void printDuration()
    {
        std::cout << "ADSR::total function duration is -> " << duration << std::endl;
    }

    ADSR();

    ~ADSR() 
    {
       std::cout << "an envelope was destroyed, make it glitch free \n"; 
    }
    
};

ADSR::ADSR() : isRunning ( false ), timeScale ( 'S' ), numberOfStages ( 4 ) { }
ADSR::Stage::Stage() : stage ('A'), stageDur ( 0.5 ), id ( 0 ) {}

//Implementation 3
ADSR::Stage ADSR::scaleCurrentStage() 
{   
    ADSR temporaryADSR;

    if ((currentStage.stageDur > 0) && (currentStage.id <= numberOfStages)) 
    {
        temporaryADSR.currentStage.stageDur = currentStage.stageDur;

        double scaleFactor = 1;

        switch (timeScale)
            {           
                case 'S':
                    scaleFactor = 0.25;
                break;
                case 'M':
                    scaleFactor = 1.5;
                break;
                case 'L':
                    scaleFactor = 10;
                break;
            }
        
        temporaryADSR.currentStage.stageDur *= scaleFactor;
        // do some wobbly work on the temporary envelope shape...
        duration += temporaryADSR.currentStage.stageDur;
    } 
    else
    {
        //go to next stage or end
        currentStage.id++;
        currentStage.id = currentStage.id%numberOfStages;
        return currentStage;
    }
    return temporaryADSR.currentStage;
}

int main() 
{
    ADSR env;
    std::cout << "Memory used by ADSR -> " << sizeof(ADSR) << " bytes" << std::endl;
    env.scaleStageDurationByTimeScale();
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
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        CheckBox()
        {
            size = 16.0f;
            icon = '#';           
        }

        CheckBox(float s) : size (s) {}

        // destructor generates [-Wdeprecated] warning
        // TODO: learn to resolve this warning later in the course
        /** 
        ~CheckBox()
        {
            std::cout  << "Check box destructed.";
        }
        **/

        bool isChecked { false };
        bool isVisible { true };
        float size;
        char icon;

        //lifetime task func...
        bool animateCheckBox (std::string fieldID, CheckBox c, float animationTime);  
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
    void checkABox (CheckBox )
    {
        std::cout << "\u2713 \t";
        this->checkBox.isChecked = true;
    }
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
                            fieldCheckBox (  )
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

bool Form::CheckBox::animateCheckBox (std::string , CheckBox check_box, float anim_time )
{
    /*
        do funky animation for a UDT CheckBox
        related to a UDT Field of a certain id
        of course this would be multi threaded or something not with a while loop!
    */
    float startingSize = check_box.size;
    float shrinkingSize = startingSize;
    std::string unicode = "\u2593";
    while ((check_box.isChecked) && (shrinkingSize > 0.01f)) 
    {
       shrinkingSize -= (anim_time/60.0f);
       if (shrinkingSize/startingSize < 0.75f) unicode = "\u2592";
       if (shrinkingSize/startingSize < 0.125f) unicode = "\u2591";  
       
       if (!check_box.isChecked) 
        {
            check_box.size = startingSize;
            return false;
        } // user changed their mind during animation
        
        std::cout << unicode; //draw the animation
    }; 
    return true; // vanished!
}

int main()
{
    Form submitUserData;
    std::cout << "Memory used by Form -> " << sizeof(Form) << " bytes \n" ;
    submitUserData.print_IDs();
    submitUserData.checkABox(submitUserData.checkBox);
    submitUserData.checkBox.animateCheckBox("name", submitUserData.checkBox, 30.0f);
    std::cout << "\n";
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
            std::time_t timeSeed;
            std::time (&timeSeed); 
            numberOfChars = {8};
            name = "empty";
        }

        std::string name;
        unsigned int numberOfChars;

        //std::string getRandomChars (long, unsigned int, std::string);
    };

    PresetName presetNameObject;

    char bank;
    int presetNumber = { 001 };
    bool hasBeenEdited = { false };
    unsigned seed;
    std::string noisyKey;
    //std::string presetName;

    bool updatePresets();
    PresetLibrary dumpBank (char bank);
    std::string generateRandomName();
    std::string getPresetName();

    //default constructor 
    PresetLibrary();
    //seedable constructor
    PresetLibrary(unsigned aNewSeed) { seed = aNewSeed; }
};

PresetLibrary::PresetLibrary() : bank ( 'A' ), seed ( 1 ) { }

//Implementations 5
std::string PresetLibrary::generateRandomName ()
{
    std::string result = "";
    std::mt19937 randomStream (this->seed); //Standard mersenne_twister_engine seeded with int
    std::uniform_int_distribution<> nextRandomInRange(65, 90);

    for (unsigned i=0; i<= presetNameObject.numberOfChars; ++i) 
    {
        result += static_cast<char>(nextRandomInRange(randomStream)); 
    }
    this->presetNameObject.name = result;
    return result;
}

std::string PresetLibrary::getPresetName()
{
    return presetNameObject.name;
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
    PresetLibrary pl(137); 
    pl.generateRandomName();
    std::cout << "Memory used by PresetLibrary -> " << sizeof(PresetLibrary) << " bytes" << std::endl;
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
static double initialGlobalBufferSize = 2048;
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
        int loopCounter = { 0 };
        double bufferSize = setGetSizeInSamples( 2 );
        double defaultBufferSize = { 2048 }; 
        bool isEmpty = { true };

        double setGetSizeInSamples ( int );
        bool clearBuffer (Buffer );
        bool copyToSecondaryBuffer (SecondaryBuffer );

        Buffer();        
    };

    double defaultBufferSize;
    int numberOfBuffers;
    Buffer mainBuffer;

    double getDefaultBufferSize()
    {
        return defaultBufferSize;
    }
    
    FunkyBufferPlayer();
};

FunkyBufferPlayer::FunkyBufferPlayer() :
                                        defaultBufferSize ( initialGlobalBufferSize ),
                                        numberOfBuffers ( 4 ),
                                        mainBuffer ( Buffer () )
{ }

FunkyBufferPlayer::Buffer::Buffer() : bufferID ( 1 ), defaultBufferSize( initialGlobalBufferSize ) { }

//Implementation 6
double FunkyBufferPlayer::Buffer::setGetSizeInSamples( int size ) 
{
    //set & return the size of a Buffer instance
    double sizeInSamp;
    switch ( size )
    {
        case 1: sizeInSamp = 512; break;
        case 2: sizeInSamp = 4096; break;
        case 3: sizeInSamp = 8192; break;
        default: sizeInSamp = this->defaultBufferSize; break; 
    }
    this->bufferSize = sizeInSamp;
    return sizeInSamp;
}

bool FunkyBufferPlayer::Buffer::clearBuffer (Buffer bufferToClear)
{
     // fill some buffer with some constant really fast
     double sampsToClear = bufferToClear.bufferSize;

    //if already empty don't do loop and return false.
    if (bufferToClear.isEmpty) return false;

    for (int s=0; s < sampsToClear; ++s)
    {
        //fill the buffer with a constant
    };
    
    // return true when cleared
    return true;
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
    std::cout << "Memory used by FunkyBufferPlayer -> " << sizeof(FunkyBufferPlayer) << " bytes \n"
    << "FunkyBufferPlayer:: size of buffer " << fbp.mainBuffer.bufferID  << " is " << fbp.mainBuffer.bufferSize  << "\n"
    << "Changing buffer size \u2713 \n" ; 
    fbp.mainBuffer.setGetSizeInSamples( 3 );
    std::cout << "FunkyBufferPlayer:: try to clear buffer -> " 
    << ((fbp.mainBuffer.clearBuffer( fbp.mainBuffer )) ? "\u2713" : "\u2715") << "\n";
    fbp.mainBuffer.isEmpty = false;
    std::cout << "FunkyBufferPlayer:: buffer is now full.\n Try clear again -> " 
    << ((fbp.mainBuffer.clearBuffer( fbp.mainBuffer )) ? "\u2713" : "\u2715") << "\n"
    << fbp.mainBuffer.bufferSize << " samples cleared."
    << std::endl;
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
        float friction, accel, velocity {0.5f};
        float px,py;
        float constrainX {50.0f}, constrainY {400.0f};

        void update (std::string id, float friction, float accel, float velocity);
        float getValue (std::string id);
        float moveRelative(float , float);
        void updateFaderPosition(float, float);
    };
//  Initialising nested structs inline from list overrides constructor default values
    Fader fader1 { "kik", false, 0.55f, 0.2f, 0.4f, 100.0f, 300.0f }, 
          fader2 { "snr", true, 0.1f, 0.33f, 0.5f, 200.0f, 300.0f }, 
          fader3 { "klp", false, 0.1f, 0.3f, 0.5f, 300.0f, 300.0f }; 

    std::string printFaderPhysics();
    std::string printFaderIDs();
    void updateFaders (int numberOfFaders);    
};

//Implementation 7
float FlyingFaderBank::Fader::moveRelative(float dx, float dy) 
{
    if (px > (px+constrainX)) { dx = 0; }
    if (py > (py+constrainY)) { dy = 0; }
    updateFaderPosition( dx, dy);
    return (dx + dy); //returns magnitude
}

std::string FlyingFaderBank::printFaderPhysics()
{
    std::string result = "";
    result += (fader1.physics) ? fader1.id+" \u2713 " : fader1.id+" \u2715 ";
    result += (fader2.physics) ? fader2.id+" \u2713 " : fader2.id+" \u2715 "; 
    result += (fader3.physics) ? fader3.id+" \u2713 " : fader3.id+" \u2715 ";   
    return result;
}

void FlyingFaderBank::Fader::updateFaderPosition (float dx, float dy)
{
    px += dx; py += dy;
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

    std::cout << "Memory used by FlyingFaderBank -> " << sizeof(FlyingFaderBank) << " bytes\n"
    << "Faderbank ID & physics -> " 
    << ffb.printFaderPhysics() << "\n"
    << "fader 1 at x:" << ffb.fader1.px << " y:" << ffb.fader1.py << "\n"
    << "Moving relative....\n";
    ffb.fader1.moveRelative ( 0.0f, -20.0f );
    std::cout << "fader 1 at x:" << ffb.fader1.px << " y:" << ffb.fader1.py << "\n";
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
    std::string scaleName;
    
    struct Scale 
    {
        double octaves;
        double generatingRatio;
        std::vector<double> scaleFreqs;
        double constrain = 4186; // 8 c
        std::vector<double> generateScaleForOctaves ( double );
    };

    Scale genScale;

    ScaleGenerator() {scaleName = ( "Golden" ); genScale.octaves = ( 8 ); genScale.generatingRatio = ( 1.618 );}

};

//Implementation 8
std::vector<double>  ScaleGenerator::Scale::generateScaleForOctaves ( double local_generatingRatio )
{
    //naive scale generation returns as/into ScaleGenerator::Scale UDT
    double baseFreq = 32.7; // 1 c
    double currentFreq = baseFreq;
    std::vector<double> scaleVector;
    size_t index = 0;
    
    while (currentFreq < constrain)
    {
        currentFreq += (currentFreq * (local_generatingRatio/12));
        scaleVector.push_back(currentFreq);
       
        std::cout << currentFreq << ", ";
        index++;
    }
     std::cout << "\n \u2713 \t " << index << " frequencies generated \n";
    return scaleVector;
}

int main() 
{
    ScaleGenerator myScale;
    std::cout << "Memory used by ScaleGenerator -> " << sizeof(ScaleGenerator) << " bytes \n"
    << myScale.scaleName << " scale generating ratio -> " << myScale.genScale.generatingRatio << "\n";
    myScale.genScale.generateScaleForOctaves (myScale.genScale.generatingRatio);
    
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
            float fadeFactor;

            void destroy();
            void draw (int , float );
                       
            Segment(); 

            ~Segment()
            {
                segmentIndex = -1; activeStatus = false;
                destroy();
            }

        };

        Segment m_Segment { } ; // Segment struct initialiser?

        void updateSegment (int meterID, Segment s);
    };

    VerticalMeter vumeterType1 { 64, 16, 50, 10 };   
    VerticalMeter vumeterType2 { 16, 64, 50, 50 }; 
};

Meter::VerticalMeter::Segment::Segment() :
                                        segmentIndex ( 0 ),
                                        opacity ( 1.f ),
                                        activeStatus ( true ),
                                        fadeFactor ( 0.001f )
{}

//Implementation 9
void Meter::VerticalMeter::updateSegment (int, Meter::VerticalMeter::Segment)
{
    //update segment graphics style
}

void Meter::VerticalMeter::Segment::draw (int , float )
{   
    // arguments segmentIndex, opacity
    // redraw an instance of a Segment UDT
}

void Meter::VerticalMeter::Segment::destroy()
{
     //executes when removing an instance of a Segment UDT from memory 
    float anim_time = 3;
    float starts = opacity;
    float local_opacity = starts;
    std::string unicode = "\u2593";
    while (local_opacity > 0.1f) 
    {
        local_opacity -= (anim_time/60.0f);
        if (local_opacity/starts < 0.75f) unicode = "\u2592";
        if (local_opacity/starts < 0.25f) unicode = "\u2591";          
        std::cout << unicode; //draw the animation
    }; 
    std::cout << "\n" << std::endl;
}


int main() 
{
    Meter vu1, vu2;

    std::cout << "Memory used by Meter -> " << sizeof(Meter) << " bytes\n"
    << "VuMeter1 x y w h ->  " << vu1.vumeterType1.x << "," << vu1.vumeterType1.y
    << "," << vu1.vumeterType1.w <<  "," << vu1.vumeterType1.h << "\n"
    << "VuMeter2 x y w h ->  " << vu2.vumeterType2.x << "," << vu1.vumeterType2.y
    << "," << vu2.vumeterType2.w <<  "," << vu2.vumeterType2.h 
    << "\nDestructor fades out segments when main() ends why are there four? -> \n"; // why are there four calls to the ~Segment destuctor?
    std::cout << "\n";
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
    bool isBackwards;

    int stepForward ();

    StepSequencer();
};

StepSequencer::StepData::StepData() :
                                currentStage ( 0 ),
                                gateStatus ( true ),
                                duration ( 1.0 )                            
{ }

StepSequencer::StepSequencer() :
                                isPlaying ( false ),
                                numberOfSteps ( 8 ),
                                tempo ( 120 ),
                                id ( 1 ),   
                                isBackwards ( false )
{ }


//Implementation 10

int StepSequencer::stepForward () 
{
    int localStepSize;
    localStepSize = (isBackwards) ? -1 : 1;
    int local_currentStage = currentStage;

    if (isPlaying) 
    {       
        local_currentStage += localStepSize; 
        currentStage = abs(local_currentStage%numberOfSteps);
    }
    else
    {
        currentStage = 0;
    }
return currentStage;
}


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

    std::cout << "Memory used by StepSequencer -> " << sizeof(StepSequencer) << " bytes \n"
    << "Sequencer:: Pitch Class -> " << s1.pitchClass << "\n"
    << "Starting sequencer -> \n";
    s1.isPlaying = true;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //initialise biased PRNG
    int randomInt = 0;
    std::string playSign = "";

    for (int i=48; i>0; --i) 
    {
        playSign = " \u21E8 ";
        randomInt = static_cast<int>(std::rand()%10);
        // 50% chance of flipping direction...
        if (randomInt < 5) 
        {
            s1.isBackwards = !s1.isBackwards;
            playSign = " \u21E6 ";
        }
        std::cout << playSign << s1.stepForward();
    }
    return 0;
}
}

#include <iostream>
int main()
{
    std::string separator = "\n------------------------------\n";
	//Example::main();
    std::cout << separator;
    KitchenExample::main();
    std::cout << separator;
    KioskLocatorTask::main();
    std::cout << separator;
    ADSRTask::main();
    std::cout << separator;
    FormTask::main();
    std::cout << separator;
    PresetLibraryTask::main();
    std::cout << separator;
    FunkyBufferPlayerTask::main();
    std::cout << separator;
    FaderBankTask::main();
    std::cout << separator;
    ScaleGeneratorTask::main();
    std::cout << separator;
    MetersTask::main();
    std::cout << separator;
    SequencerTask::main();
    std::cout << separator;
    std::cout << "good to go!" << std::endl;
}
