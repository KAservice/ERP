#ifndef UHLP_DMSprImageGrpCFH                  
#define UHLP_DMSprImageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprImageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprImageGrpCF();                                                           
   ~THLP_DMSprImageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
