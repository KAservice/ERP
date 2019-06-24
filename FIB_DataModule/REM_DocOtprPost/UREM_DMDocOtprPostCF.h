#ifndef UREM_DMDocOtprPostCFH                  
#define UREM_DMDocOtprPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocOtprPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocOtprPostCF();                                                           
   ~TREM_DMDocOtprPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
