#ifndef UFormaDialogaCFH                  
#define UFormaDialogaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDialogaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDialogaCF();                                                           
   ~TFormaDialogaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
