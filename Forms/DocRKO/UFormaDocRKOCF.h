#ifndef UFormaDocRKOCFH                  
#define UFormaDocRKOCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRKOCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRKOCF();                                                           
   ~TFormaDocRKOCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
