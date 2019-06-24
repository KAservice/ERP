#ifndef UFormaGurAllDocCFH                  
#define UFormaGurAllDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurAllDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurAllDocCF();                                                           
   ~TFormaGurAllDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
