#ifndef UREM_DMDocKM2CFH                  
#define UREM_DMDocKM2CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocKM2CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocKM2CF();                                                           
   ~TREM_DMDocKM2CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
