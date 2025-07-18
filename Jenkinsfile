pipeline {
  agent any

  stages {
    stage('Checkout') {
      steps { git 'https://your.repo.url.git' }
    }
    stage('Build Docker') {
      steps { script { docker.build('lung-ct') } }
    }
    stage('Run Segmentation') {
      steps {
        script {
          docker.image('lung-ct').inside {
            sh './lung_ct'
          }
        }
      }
    }
    stage('Archive Results') {
      steps {
        archiveArtifacts artifacts: 'results/*.png', fingerprint: true
      }
    }
  }
}
