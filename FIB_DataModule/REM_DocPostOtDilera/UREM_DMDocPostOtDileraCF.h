#ifndef UREM_DMDocPostOtDileraCFH                  
#define UREM_DMDocPostOtDileraCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocPostOtDileraCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocPostOtDileraCF();                                                           
   ~TREM_DMDocPostOtDileraCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
