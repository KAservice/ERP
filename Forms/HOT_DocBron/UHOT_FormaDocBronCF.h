#ifndef UHOT_FormaDocBronCFH                  
#define UHOT_FormaDocBronCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaDocBronCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaDocBronCF();                                                           
   ~THOT_FormaDocBronCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
