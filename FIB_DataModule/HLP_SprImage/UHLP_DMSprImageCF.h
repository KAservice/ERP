#ifndef UHLP_DMSprImageCFH                  
#define UHLP_DMSprImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprImageCF();                                                           
   ~THLP_DMSprImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
