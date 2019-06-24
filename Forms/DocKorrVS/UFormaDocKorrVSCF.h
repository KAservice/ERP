#ifndef UFormaDocKorrVSCFH                  
#define UFormaDocKorrVSCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocKorrVSCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocKorrVSCF();                                                           
   ~TFormaDocKorrVSCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
