#ifndef UREM_FormaDocPerServCentrCFH                  
#define UREM_FormaDocPerServCentrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocPerServCentrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocPerServCentrCF();                                                           
   ~TREM_FormaDocPerServCentrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
