#ifndef UFormaDocOstVsCFH                  
#define UFormaDocOstVsCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocOstVsCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocOstVsCF();                                                           
   ~TFormaDocOstVsCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
