#ifndef UHLP_DMSprPageGrpCFH                  
#define UHLP_DMSprPageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprPageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprPageGrpCF();                                                           
   ~THLP_DMSprPageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
