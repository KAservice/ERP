#ifndef UFormaDocIsmPriceCFH                  
#define UFormaDocIsmPriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocIsmPriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocIsmPriceCF();                                                           
   ~TFormaDocIsmPriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
