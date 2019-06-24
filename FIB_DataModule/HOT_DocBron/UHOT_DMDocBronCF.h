#ifndef UHOT_DMDocBronCFH                  
#define UHOT_DMDocBronCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMDocBronCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMDocBronCF();                                                           
   ~THOT_DMDocBronCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
